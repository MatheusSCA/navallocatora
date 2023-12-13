
const express = require('express');
const { PrismaClient } = require('@prisma/client');
const cors = require('cors');

const app = express();
const prisma = new PrismaClient();

app.use(cors());
app.use(express.json());


app.post('/usuarios', async (req, res) => {
    try {
      const { nome, email, senha, profissao, termos } = req.body;
  
    
      const usuarioExistente = await prisma.user.findFirst({
        where: {
          OR: [
            { nome: nome },
            { email: email },
          ],
        },
      });
  
      if (usuarioExistente) {
        return res.status(400).json({ erro: 'Este usuário já existe' });
      }
      
      const novoUsuario = await prisma.user.create({
        data: {
          nome,
          email,
          senha,
          profissao,
          termos,
        },
      });
  
      res.json(novoUsuario);
    } catch (error) {
      console.error('Erro ao criar usuário:', error);
      res.status(500).json({ erro: 'Erro ao criar usuário' });
    }
  });
  

app.get('/usuarios', async (req, res) => {
    try {
      const usuarios = await prisma.user.findMany();
      res.json(usuarios);
    } catch (error) {
      console.error('Erro ao obter usuários:', error);
      res.status(500).json({ erro: 'Erro ao obter usuários' });
    }
  });
  



app.put('/usuarios/:id', async (req, res) => {
  try {
    const { id } = req.params;
    const { nome, email, senha, profissao, termos } = req.body;
    
    const usuarioAtualizado = await prisma.user.update({
      where: {
        id: parseInt(id),
      },
      data: {
        nome,
        email,
        senha,
        profissao,
        termos,
      },
    });

    res.json(usuarioAtualizado);
  } catch (error) {
    console.error('Erro ao atualizar usuário:', error);
    res.status(500).json({ erro: 'Erro ao atualizar usuário' });
  }
});

app.delete('/usuarios/:id', async (req, res) => {
  try {
    const { id } = req.params;
    
    await prisma.user.delete({
      where: {
        id: parseInt(id),
      },
    });

    res.json({ mensagem: 'Usuário excluído com sucesso' });
  } catch (error) {
    console.error('Erro ao excluir usuário:', error);
    res.status(500).json({ erro: 'Erro ao excluir usuário' });
  }
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Servidor rodando na porta ${PORT}`);
});
