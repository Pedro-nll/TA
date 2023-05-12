function adicionar(id) {
    let elem = document.getElementById(id).innerHTML;
    document.getElementById("caixaResultado").innerHTML += elem;
}

function reset() {
    document.getElementById("caixaResultado").innerHTML = "";
}

function resultado(){
    let elem = document.getElementById("caixaResultado").innerHTML;
    let x = eval(elem);
    document.getElementById("caixaResultado").innerHTML = x;
}