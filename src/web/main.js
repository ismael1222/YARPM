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