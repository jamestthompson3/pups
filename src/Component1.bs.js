// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Component2$ReactTemplate = require("./Component2.bs.js");

var component = ReasonReact.statelessComponent("Page");

function handleClick(_, _$1) {
  console.log("clicked!");
  return /* () */0;
}

function make(message, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", {
                          style: {
                            display: "flex",
                            height: "100%",
                            width: "100%",
                            alignItems: "center",
                            flexDirection: "column",
                            justifyContent: "space-around"
                          }
                        }, React.createElement("h1", undefined, message), ReasonReact.element(undefined, undefined, Component2$ReactTemplate.make(/* array */[])));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.handleClick = handleClick;
exports.make = make;
/* component Not a pure module */
