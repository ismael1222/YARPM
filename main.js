newElementsP = document.getElementById("newElements");
exitedElementsP = document.getElementById("exitedElements");
counterElement = document.getElementById("counter")
var oldElements = [];
var counter = 0;
function hasAthatBdoesnt(A, B) {
    var result = [];
    A.forEach(item => {
        if (! B.includes(item)) {
            result.push(item)
        }
    })
    return result;
}
setInterval(() => {
    queryProcesses().then(currentElements => {
        let newItems = hasAthatBdoesnt(currentElements, oldElements); // update new elements
        newElementsP.innerHTML = newItems // increment counter
        counterElement.innerHTML = ++ counter // update old elements
        let exitedElements = hasAthatBdoesnt(oldElements, currentElements);
        exitedElementsP.innerHTML = exitedElements; // newelements get old
        oldElements = currentElements;
    })

}, 1000);
