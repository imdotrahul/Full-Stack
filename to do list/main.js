const todo = ["make dinner"];
list2();
function list2() {
    let htmlelement = " ";

    for (let i = 0; i < todo.length; i++) {
        const todolist = todo[i];
        const html = `<p>${todolist}</p>`;
        htmlelement += html;
    }
    console.log(htmlelement);
    document.querySelector(".divtag").innerHTML = htmlelement;
}

function AddToDo() {
    const addedelement = document.querySelector(".input-1");
    const name = addedelement.value;
    todo.push(name);
    console.log(todo);
    addedelement.value = "";

    list2();
}
