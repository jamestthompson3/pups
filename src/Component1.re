/* This is the basic component. */
let component = ReasonReact.statelessComponent("Page");

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
let handleClick = (_event, _self) => Js.log("clicked!");

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `pup` is a named argument, which simulates ReactJS props. Usage:

   `<Page pup="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~pup="hello", [||]))` */
let make = (~message, _children) => {
  ...component,
  render: self =>
    <div style=(ReactDOMRe.Style.make(~width="100%", ~height="100%", ~display="flex", ~flexDirection="column", ~justifyContent="space-around", ~alignItems="center", ()))>
      <h1>(ReasonReact.string(message))</h1>
      <Component2 />
    </div>,
};


