var categoriasSelecionadas = [];
var filtroPreco = 0;
var produtoMaisCaro = 0;
var primeiraVez = 0;

async function buscarProdutos() {
    let busca;
    if (categoriasSelecionadas.length > 0) {
        busca = await fetch(`https://diwserver.vps.webdock.cloud/products${categoriasSelecionadas}`);
    } else {
        busca = await fetch('https://diwserver.vps.webdock.cloud/products');
    }
    let resultadosJson = await busca.json();
    if(resultadosJson.products){
        resultados = resultadosJson.products
    }else{
        resultados = resultadosJson
    }
    let produtosFiltrados = resultados
    $(function() {
        // Inicializa o slider
        $("#slider").slider({
            range: "min",
            min: 1,
            max: produtoMaisCaro,
            value: filtroPreco,
            slide: function(event, ui) {
                filtroPreco = ui.value;
                $("#valorSlider").text(filtroPreco);
                buscarProdutos();
            }
        });
        $("#valorSlider").text(filtroPreco);
    });
    if (primeiraVez === 0) {
        for (let i = 0; i < resultados.length; i++) {
            if (resultados[i].price > produtoMaisCaro) produtoMaisCaro = resultados[i].price;
        }
        primeiraVez = 1;
    }else{
        if(filtroPreco != 0){
            produtosFiltrados = resultados.filter(function(produto) {
                return produto.price <= filtroPreco;
            });
        }
    }
    document.getElementById('itens').innerHTML = '';
    for (let i = 0; i < produtosFiltrados.length; i++) {
        let estrelas = '';
        for (let j = 0; j < produtosFiltrados[i].rating.rate; j++) {
            estrelas += `<i class="bi bi-star-fill"></i>`;
        }
        document.getElementById('itens').innerHTML += `
            <div class="card card-item">
                <img src="${produtosFiltrados[i].image}" class="card-img-top img-fluid" style="max-width: 200px" />
                <div class="card-body">
                    <h5>${produtosFiltrados[i].title}</h5>
                    <p class="card-text">${produtosFiltrados[i].description}</p>
                    ${estrelas}<br>
                    <b>$${produtosFiltrados[i].price}</b><br>
                    <a href="detalhes.html" class="btn btn-primary" onclick="pagDetalhes(${produtosFiltrados[i].id})">Mais detalhes</a>
                </div>
            </div>`;
    }
}
$("#logo").click(function(){
    window.location.href="index.html"
})
function selecionarCategoria() {
    const categoria = document.getElementById('categorias').value;
    if (categoria == 0) {
        categoriasSelecionadas = [];
    } else {
        categoriasSelecionadas = ["/category/"+categoria];
    }
    buscarProdutos();
}

async function buscarCategorias() {
    let busca = await fetch('https://diwserver.vps.webdock.cloud/products/categories');
    let resultados = await busca.json();
    for (let i = 0; i < resultados.length; i++) {
        document.getElementById('categorias').innerHTML += `<option value="${resultados[i]}">${resultados[i]}</option>`;
    }
}

function pagDetalhes(id) {
    if(localStorage.getItem('detalhesId')){
        localStorage.removeItem('detalhesId');
    }
    localStorage.setItem('detalhesId', String(id));
    window.location.href = 'detalhes.html';
}


document.addEventListener("DOMContentLoaded", function () {
    buscarCategorias();
    buscarProdutos();
});
