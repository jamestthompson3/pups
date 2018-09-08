/* The new stdlib additions */
open Belt;

type dog = string;

type savedPups = Some(list(string)) | None;

type state =
  | Inactive
  | Loading
  | Error
  | Loaded(dog);

type action =
  | DogsFetch
  | DogsFetched(dog)
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
  initialState: _state => Inactive,
  reducer: (action, _state) =>
    switch (action) {
    | DogsFetch =>
      ReasonReact.UpdateWithSideEffects(
        Loading,
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
    | DogsFetched(dogs) => ReasonReact.Update(Loaded(dogs))
    | DogsFailedToFetch => ReasonReact.Update(Error)
    },
  render: self =>
    switch (self.state) {
      | Inactive =>
    <div
      style=(
        ReactDOMRe.Style.make(
          ~display="flex",
          ~flexDirection="column",
          ~justifyContent="space-between",
          ~alignItems="center",
          ~height="300px",
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

    | Error => <div> (ReasonReact.string("An error occurred!")) </div>
    | Loading => <div> (ReasonReact.string("Loading...")) </div>
    | Loaded(dog) =>
      <div style=(ReactDOMRe.Style.make(~display="flex", ~flexDirection="column", ~alignItems="center", ~justifyContent="space-around", ()))>
        <Image source=dog />
        <input style=(ReactDOMRe.Style.make(~border="none", ~borderBottom="1px solid", ~textAlign="center", ~background="transparent", ~padding="0px 8px", ~display="flex", ~alignItems="center", ~marginTop="10px", ())) placeholder="give your pup a name"/>
      </div>
    },
};
