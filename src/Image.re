let component = ReasonReact.statelessComponent("ImageHolder");

let make = (~source, _children) => {
  ...component,
  render: _self =>
    source == "" ?
      ReasonReact.null :
      <img
        style=(
          ReactDOMRe.Style.make(
            ~borderRadius="3px",
            ~width="200px",
            ~height="200px",
            ~boxShadow="0 0 3px 2px #00000054",
            ()
          )
        )
        src=source
      />
};
