const id = localStorage.getItem('detalhesId');
async function carregarInfo(){
    resposta = await fetch(`https://diwserver.vps.webdock.cloud/products/${id}`)
    const detalhes = await resposta.json()
    document.getElementById('imagem').innerHTML += `<img src="${detalhes.image}" class="img-fluid" />`
    document.getElementById('resto').innerHTML += `<h3 class="fs-1">${detalhes.title}</h3><h5 class="fs-2">$${detalhes.price}</h5><h6 class="fs-3">Rating: ${detalhes.rating.rate}/5</h6><p class="fs-4"><span class="fw-bold"> Descrição: </span> ${detalhes.description}</p> <p>`
}
$("#logo").click(function(){
    window.location.href="index.html"
})
document.addEventListener("DOMContentLoaded", function () {
    carregarInfo();
})
