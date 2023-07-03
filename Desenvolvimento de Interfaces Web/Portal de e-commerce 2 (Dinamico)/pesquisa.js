let termoDePesquisa = ''
async function buscarProdutos(){
    let busca;
    if(termoDePesquisa.length>0){
        busca = await fetch(`https://diwserver.vps.webdock.cloud/products/search?query=${termoDePesquisa}`);
    }else{
        busca = await fetch(`https://diwserver.vps.webdock.cloud/products`);
    }
    let resultados;
    let buscaJson = await busca.json();
    if(buscaJson.products){
        resultados = buscaJson.products; 
    }else{
        resultados = buscaJson;
    }
    document.getElementById('itens').innerHTML = '';
    for (let i = 0; i < resultados.length; i++) {
        let estrelas = '';
        for (let j = 0; j < resultados[i].rating.rate; j++) {
            estrelas += `<i class="bi bi-star-fill"></i>`;
        }
        document.getElementById('itens').innerHTML += `
            <div class="card card-item">
                <img src="${resultados[i].image}" class="card-img-top img-fluid" style="max-width: 200px" />
                <div class="card-body">
                    <h5>${resultados[i].title}</h5>
                    <p class="card-text">${resultados[i].description}</p>
                    ${estrelas}<br>
                    <b>$${resultados[i].price}</b><br>
                    <a href="detalhes.html" class="btn btn-primary" onclick="pagDetalhes(${resultados[i].id})">Mais detalhes</a>
                </div>
            </div>`;
    }
}

function pagDetalhes(id) {
    if(localStorage.getItem('detalhesId')){
        localStorage.removeItem('detalhesId');
    }
    localStorage.setItem('detalhesId', String(id));
    window.location.href = 'detalhes.html';
}

document.getElementById('busca').addEventListener("click", function(event){
    event.preventDefault();
    let termo = document.getElementById('barraBusca').value
    termoDePesquisa = '' + termo
    buscarProdutos();
});

$("#logo").click(function(){
    window.location.href="index.html"
})


document.addEventListener("DOMContentLoaded", function(){
    buscarProdutos();
})