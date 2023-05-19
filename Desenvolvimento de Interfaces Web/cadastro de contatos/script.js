$(document).ready(function () {
    // Cria um array para armazenar os contatos; Se no local storage já existir esse array utiliza ele;
    var listaContatos = JSON.parse(localStorage.getItem('listaContatos')) || [];

    // Função para adicionar um novo contato
    function adicionarContato(contato) {
        // Adiciona o contato com as informações nome e telefone ao array que armazena os contatos
        listaContatos.push(contato);
        // Adiciona a lista de contatos no local storage
        localStorage.setItem('listaContatos', JSON.stringify(listaContatos));
    }

    //Cria a apresentação dos contatos
    function atualizarApresentacaoContatos() {
        // Limpa a tabela de apresentação de contatos
        $("#apresentacaoContatos").empty();

        // Percorre a lista de contatos e cria as linhas e células da tabela
        listaContatos.forEach(function (contato) {
            var row = $("<tr>");
            var nomeCell = $("<td>").text(contato.nome);
            var telefoneCell = $("<td>").text(contato.telefone);
            var editarCell = $("<td>").html("<button class='btn btn-warning' id='editarBtn'>Editar</button>");
            var excluirCell = $("<td>").html("<button class='btn btn-danger' id='excluirBtn'>Excluir</button>");
            row.append(nomeCell, telefoneCell, editarCell, excluirCell);
            $("#apresentacaoContatos").append(row);
        });
    }
    // Cria uma função para o clique do botão submit
    $("#submit").click(function () {
        // Cria um objeto que irá armazenar os dados do contato
        var contato = {
            nome: $("#nome").val(),
            telefone: $("#telefone").val()
        };

        // Adiciona o novo contato
        adicionarContato(contato);

        // Reseta os campos do formulário
        $("#nome").val('');
        $("#telefone").val('');

        // Atualiza a apresentação dos contatos na tabela
        atualizarApresentacaoContatos();
    });

    // Cria uma função para editar os contatos
    $("#apresentacaoContatos").on("click", "#editarBtn", function () {
        // Pega o nome do contato que será editado
        var nomeContato = $(this).closest("tr").find("td:nth-child(1)").text();

        // Percorre a lista de contatos
        for (var i = 0; i < listaContatos.length; i++) {
            var contato = listaContatos[i];
            // Verifica se o nome do contato é igual ao nome do contato que será editado
            if (contato.nome === nomeContato) {
                // Preenche os campos do formulário com as informações do contato
                $("#nome").val(contato.nome);
                $("#telefone").val(contato.telefone);

                // Remove o contato da lista
                listaContatos.splice(i, 1);
                break;
            }
        }

        // Atualiza a lista de contatos no local storage
        localStorage.setItem('listaContatos', JSON.stringify(listaContatos));

        // Atualiza a apresentação dos contatos na tabela
        atualizarApresentacaoContatos();
    });


    //Cria uma função para excluir os contatos
    $("#apresentacaoContatos").on("click", "#excluirBtn", function () {
        // Pega o nome do contato que será excluído
        var nomeContato = $(this).parents("tr").find("td:nth-child(1)").text();

        // Percorre a lista de contatos
        listaContatos.forEach(function (contato, index) {
            // Verifica se o nome do contato é igual ao nome do contato que será excluído
            if (contato.nome === nomeContato) {
                // Remove o contato da lista
                listaContatos.splice(index, 1);
            }
        });

        // Atualiza a lista de contatos no local storage
        localStorage.setItem('listaContatos', JSON.stringify(listaContatos));

        // Atualiza a apresentação dos contatos na tabela
        atualizarApresentacaoContatos();
    });

    atualizarApresentacaoContatos();
});
