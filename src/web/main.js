setInterval(() => {
    queryProcesses().then(res => {
    })
}, 1000);
function showAppId() {
  document.getElementById("appID").classList.remove("hidden");
}

function showMain() {
  document.getElementById("appID").classList.add("hidden");
}
function copyLink(){
  // Get the text field
  var copyText = document.getElementById("link");

  // Select the text field
  copyText.select();
  copyText.setSelectionRange(0, 99999); // For mobile devices

   // Copy the text inside the text field
  navigator.clipboard.writeText(copyText.value);
  document.getElementById("copy").classList.add("touched");
  document.getElementById("copy").innerHTML = "Copied   "
} 
function enterTuto(){
    document.getElementById("main").classList.add("opaco")
    document.getElementById("appID").classList.add("show")
}
function exitTuto(){
    document.getElementById("appID").classList.remove("show")
    document.getElementById("main").classList.remove("opaco")
}