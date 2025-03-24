#  Sistema de Controle de Acesso por Senha

##  Sobre o Projeto
Este projeto implementa um **sistema de controle de acesso** baseado em um **teclado matricial**, um **display LCD** e **integração Bluetooth**. O usuário pode definir uma senha e utilizá-la para abrir uma porta. O sistema também conta com um botão para fechar a porta manualmente e um **módulo Bluetooth**, permitindo controle remoto da abertura e fechamento.

##  Tecnologias Utilizadas
- **Linguagem:** C
- **Microcontroladores:** PIC
- **Periféricos:** Teclado matricial 4x4, Display LCD 16x2, Módulo Bluetooth HC-05
- **Atuação Física:** Motor para abertura e fechamento da porta

##  Funcionalidades
✅ Permite o usuário **definir uma senha** de 4 dígitos  
✅ Valida a senha digitada e **autoriza a abertura da porta**  
✅ Bloqueia acesso com **contagem de tentativas incorretas**  
✅ Usa um **botão físico** para fechar a porta manualmente  
✅ **Integração Bluetooth** para controle remoto via aplicativo móvel  
✅ **Porta com motor** já implementada para automação completa  


##  Como Usar
1️⃣ **Ligar o sistema** e definir uma senha de 4 dígitos.  
2️⃣ **Digitar a senha** corretamente para abrir a porta.  
3️⃣ **Se errar a senha**, o sistema exibe uma mensagem de erro e aumenta o contador de tentativas.  
4️⃣ **Para fechar a porta**, pressione o botão conectado ao **PORTC.b7** ou utilize o aplicativo via Bluetooth.  
5️⃣ Para redefinir a senha, pressione a tecla **'#'** no teclado.  
6️⃣ **Controle remoto:** Utilize um aplicativo Bluetooth para abrir/fechar a porta remotamente.

##  Estrutura do Código
- **Inicialização:** Configura o teclado, display LCD, Bluetooth e botões.
- **Definição da Senha:** O usuário insere uma senha de 4 dígitos.
- **Validação da Senha:** O sistema verifica se a senha digitada é correta.
- **Abertura e Fechamento da Porta:** Controla o estado da porta baseado na senha, no botão físico e nos comandos Bluetooth.
