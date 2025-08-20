newElementsP = document.getElementById("newElements");
exitedElementsP = document.getElementById("exitedElements");
counterElement = document.getElementById("counter");
allElements = document.getElementById("allElements");
var oldElements = [];
var counter = 0;

setInterval(() => {
    queryProcesses().then(currentElements => {
        let allItems = currentElements;
        allElements.innerHTML = JSON.stringify(allItems);
        oldElements = currentElements; // newelements get old
    })
}, 1000);