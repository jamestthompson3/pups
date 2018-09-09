/* The new stdlib additions */
open Belt;

type dog = string;

type savedPups =  {
  name: string,
  imageSrc: string
};

let getSource = (dog) => {
  switch(dog) {
    | None => ""
    | Some(string) => string
  }
};

type stateStatus =
  | Inactive
  | Loading
  | Error
  | Loaded;

type state = {
  status: stateStatus,
  savedPups: list(savedPups),
  dog: option(string),
  name: string
};

type action =
  | DogsFetch
  | DogsFetched(dog)
  | NamePup(string)
  | SavePup
  | DogsFailedToFetch;

module Decode = {
  let dogs = json: dog =>
    Json.Decode.(
      json |> field("message", string)
    );
};

let component = ReasonReact.reducerComponent("FetchExample");

let make = _children => {
  ...component,
  initialState: _state => { status: Inactive, dog: None, savedPups: [], name: "" },
  reducer: (action, state) =>
    switch (action) {
    | DogsFetch =>
      ReasonReact.UpdateWithSideEffects(
        { status: Loading, dog: None, savedPups: state.savedPups, name: "" },
        (
          self =>
            Js.Promise.(
              Fetch.fetch("https://dog.ceo/api/breeds/image/random")
              |> then_(Fetch.Response.json)
              |> then_(json =>
                   json
                   |> Decode.dogs
                   |> (dogs => self.send(DogsFetched(dogs)))
                   |> resolve
                 )
              |> catch(_err =>
                   Js.Promise.resolve(self.send(DogsFailedToFetch))
                 )
              |> ignore
            )
        ),
      )
    | DogsFetched(dog) => ReasonReact.Update({ status: Loaded, dog: Some(dog), savedPups: state.savedPups, name: "" })
    | DogsFailedToFetch => ReasonReact.Update({ ...state,  status: Error })
    | NamePup(name) => ReasonReact.Update({ ...state, name })
    | SavePup => ReasonReact.Update({ status: Inactive, dog: None, savedPups: [{ name: state.name, imageSrc: getSource(state.dog)}, ...state.savedPups ], name: ""})
    },
  render: self =>
    switch (self.state.status) {
      | Inactive =>
    <div className="gallery">
    <div className="side">
    (
      Array.map(List.toArray(self.state.savedPups), pup =>
        <div className="gallery-image">
        <Image source=pup.imageSrc />
        <h3>(ReasonReact.string(pup.name))</h3>
        </div>
       )
      |> ReasonReact.array
      )
    </div>
    <div
    className="centered-action"
      style=(
        ReactDOMRe.Style.make(
                    ()
        )
       )>

      <Image source="" />

      <button
        onClick=(_event => self.send(DogsFetch))
        style=(
          ReactDOMRe.Style.make(
            ~background="#1782C4",
            ~color="#ffffff",
            ~padding="5px 8px",
            ~borderRadius="5px",
            ~border="none",
            ~width="250px",
            ~height="60px",
            ~cursor="pointer",
            ()
          )
        )>
        (ReasonReact.string("Find a pup!"))
      </button>
      </div>
      </div>

    | Error => <div> (ReasonReact.string("An error occurred!")) </div>
    | Loading => <div> (ReasonReact.string("Loading...")) </div>
    | Loaded =>
    <div className="gallery">
    <div className="side">
    (
      Array.map(List.toArray(self.state.savedPups), pup =>
                <div className="gallery-image">
                <Image source=pup.imageSrc />
                <h3>(ReasonReact.string(pup.name))</h3>
                </div>
      )
      |> ReasonReact.array
      )
    </div>

    <div style=(ReactDOMRe.Style.make(~display="flex", ~flexDirection="column", ~alignItems="center", ~justifyContent="space-around", ()))>
    <Image source=getSource(self.state.dog) />
    <div style=(ReactDOMRe.Style.make(~display="flex", ~marginTop="10px", ~width="300px", ~justifyContent="space-between", ~alignItems="baseline", ()))>
    <input style=(
      ReactDOMRe.Style.make(
        ~border="none",
        ~height="30px",
        ~borderBottom="1px solid",
        ~textAlign="center",
        ~background="transparent",
        ~padding="0px 8px",
        ~display="flex",
        ~alignItems="center",
        ())
    )
    placeholder="give your pup a name"
    onChange=(
      event => self.send(NamePup(ReactEvent.Form.target(event)##value))
    )
    autoFocus=true
    />
    <button
    onClick=(_event => self.send(SavePup))
    style=(
      ReactDOMRe.Style.make(
        ~background="#1782C4",
        ~color="#ffffff",
        ~padding="5px 8px",
        ~borderRadius="5px",
        ~border="none",
        ~width="70px",
        ~height="30px",
        ~cursor="pointer",
        ()
      )
    )>
    (ReasonReact.string("save"))
    </button>

    </div>
    </div>
    </div>
    },
};
