var { ToggleButton } = require('sdk/ui/button/toggle');
var panels = require("sdk/panel");
var self = require("sdk/self");

var button = ToggleButton ({
  id: "torrent-button",
  label: "Torrent Search",
  icon: {
    "16": "./icon-16.png",
    "32": "./icon-32.png",
    "64": "./icon-64.png"
  },
  onChange: handleChange,
  onClick: disableForThisWindow
});

var panel = panels.Panel({
  contentURL: self.data.url("./clock.html"),
  onHide: handleHide
});
function disableForThisWindow (state) {
  button.state("window", {disabled: true});
}
function handleChange (state) {
  if (state.checked) {
    panel.show ({
      position: button
    });
  }
}

function handleHide () {
  button.state('window', {checked:false});
}