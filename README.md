## Simulador de Raytracing 2D em C

Este projeto consiste em um **simulador de raytracing 2D** implementado em linguagem C, atualmente em desenvolvimento (inconpleto). A ideia é permitir a visualização de raios de luz interagindo com objetos circulares, gerando sombras e reflexões de forma didática e eficiente para estudos ou prototipação de algoritmos gráficos.

---

## 📝 Status do Projeto

- **Versão atual:** 0.1-alpha  
- **Funcionalidades implementadas:**  
  - Desenho de círculos preenchidos em SDL2  
  - Geração de raios divergindo de um ponto fonte  
  - Renderização básica de sombras projetadas -> penumbras  
- **Funcionalidades pendentes:**  
  - Cálculo de reflexões (espelhamento) -> raios refletidos em diferentes supérficies (??)
  - Otimizações de performance (uso de buffer de pixels) -> no f
  - Interface de usuário para ajuste de parâmetros em tempo real  

---

---
## 🚀 Como Compilar

1. **Pré-requisitos**  
   - GCC ou Clang  
   - SDL2 (biblioteca de gráficos)  
   - CMake ≥ 3.10  

2. **Instalação de dependências (Ubuntu/Debian)**  
   ```bash
   sudo apt update
   sudo apt install build-essential cmake libsdl2-dev
   ```

3. **Build**  
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

   O executável gerado será `raytracing2d` dentro da pasta `build/`.

---

## ▶️ Como Executar (work in progress)

Dentro do diretório `build/`, rode:

```bash
./raytracing2d
```

- Use o mouse para mover a fonte de luz.  
- Pressione **Esc** ou feche a janela para sair.

---

## 🛣️ Roadmap

1. **Reflexões e Transparência**  
   - Implementar cálculo de reflexão de raios em superfícies circulares.  

2. **Múltiplos Objetos e Texturas**  
   - Permitir carregar vários círculos com diferentes cores e materiais.  
   - Suporte a texturas básicas (imagem mapeada em formas simples).

3. **Otimização e Qualidade**  
   - Migrar desenho pixel‐a‐pixel para um buffer de cores e atualização via `SDL_UpdateTexture`.  
   - Introduzir anti-aliasing simples para suavizar as bordas.

4. **Interface Interativa**  
   - Painel de controle para alterar parâmetros (número de raios, tamanho de objetos, intensidade de luz).  

---

## 📄 Licença

Este projeto está licenciado sob a **MIT License**. Consulte o arquivo [`LICENSE`](./LICENSE) para mais detalhes.
