// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Image$ReactTemplate = require("./Image.bs.js");

function dogs(json) {
  return Json_decode.field("message", Json_decode.string, json);
}

var Decode = /* module */[/* dogs */dogs];

var component = ReasonReact.reducerComponent("FetchExample");

function make() {
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
          /* render */(function (self) {
              var match = self[/* state */1];
              if (typeof match === "number") {
                switch (match) {
                  case 0 : 
                      return React.createElement("div", {
                                  style: {
                                    display: "flex",
                                    height: "300px",
                                    alignItems: "center",
                                    flexDirection: "column",
                                    justifyContent: "space-between"
                                  }
                                }, ReasonReact.element(undefined, undefined, Image$ReactTemplate.make("", /* array */[])), React.createElement("button", {
                                      style: {
                                        background: "#1782C4",
                                        border: "none",
                                        color: "#ffffff",
                                        cursor: "pointer",
                                        height: "60px",
                                        padding: "5px 8px",
                                        width: "250px",
                                        borderRadius: "5px"
                                      },
                                      onClick: (function () {
                                          return Curry._1(self[/* send */3], /* DogsFetch */0);
                                        })
                                    }, "Find a pup!"));
                  case 1 : 
                      return React.createElement("div", undefined, "Loading...");
                  case 2 : 
                      return React.createElement("div", undefined, "An error occurred!");
                  
                }
              } else {
                return React.createElement("div", {
                            style: {
                              display: "flex",
                              alignItems: "center",
                              flexDirection: "column",
                              justifyContent: "space-around"
                            }
                          }, ReasonReact.element(undefined, undefined, Image$ReactTemplate.make(match[0], /* array */[])), React.createElement("input", {
                                style: {
                                  background: "transparent",
                                  border: "none",
                                  borderBottom: "1px solid",
                                  display: "flex",
                                  marginTop: "10px",
                                  padding: "0px 8px",
                                  textAlign: "center",
                                  alignItems: "center"
                                },
                                placeholder: "give your pup a name"
                              }));
              }
            }),
          /* initialState */(function () {
              return /* Inactive */0;
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _) {
              if (typeof action === "number") {
                if (action !== 0) {
                  return /* Update */Block.__(0, [/* Error */2]);
                } else {
                  return /* UpdateWithSideEffects */Block.__(2, [
                            /* Loading */1,
                            (function (self) {
                                fetch("https://dog.ceo/api/breeds/image/random").then((function (prim) {
                                            return prim.json();
                                          })).then((function (json) {
                                          var dogs = Json_decode.field("message", Json_decode.string, json);
                                          return Promise.resolve(Curry._1(self[/* send */3], /* DogsFetched */[dogs]));
                                        })).catch((function () {
                                        return Promise.resolve(Curry._1(self[/* send */3], /* DogsFailedToFetch */1));
                                      }));
                                return /* () */0;
                              })
                          ]);
                }
              } else {
                return /* Update */Block.__(0, [/* Loaded */[action[0]]]);
              }
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.Decode = Decode;
exports.component = component;
exports.make = make;
/* component Not a pure module */
