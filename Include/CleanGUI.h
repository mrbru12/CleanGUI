#ifndef CLEAN_CLEANGUI_H
#define CLEAN_CLEANGUI_H

// TODO: 
/* Talvez mudar o nome do projeto para Clean Pixel GUI ou Crystal Clear GUI
 * Fazer uma struct de controle geral dos Widgets (similar ao SDL_Renderer no SDL) pra poder facilitar algumas coisas (como não precisar de variáveis globais). Poderia ter a possibilidade de 
   criar mais de uma dela para, por exemplo, separar um grupo de Widgets de outro e renderizar os grupos separados em situações ou momentos diferentes. Isso poderá ajudar até mesmo a fazer 
   algumas melhorias de performance por de trás dos panos. Além de que isso também vai facilitar para o usuário, pois ele não vai precisar renderizar todos os Widgets manualmente no loop 
   de renderização, precisando só renderizar a variável do grupo oque renderizara todos os Widgets "bindados" a ele de uma só vez. 
 * A fonte padrão vai ser a Consolas
 * Eu preciso de uma opção de cor de highlight (talvez dar um jeito de fazer os highlights serem só uma sobreposição da cor do highlight, com uma opacidade baixa, na cor atual) para os Widgets 
   que fiquem ativados, como a Check Box. Isso quer dizer que na Check Box, por exemplo, o highlight vai ser feito por meio de um uniform
 * Provavelmente todos os Widgets que tiverem texto sendo renderizado de alguma forma em alguma parte dele vai ser, para facilitar, por meio de uma Label sendo setada renderizada por trás dos panos
 * O tamanho e a escala dos Widgets vai ser proporcional e depender diretamente do tamanho da fonte, além disso também vai ser adicionado o valor de margem entre a fonte e as bordas do widget. 
   Talvez seja interessante ter algum método opcional para inserir manualmente o tamanho dos Widgets, fazendo o tamanho deles não depender mais do tamanho da fonte
 * Eu vou precisar definir algumas coisas em buffers separados (como as bordas, por exemplo) pra poder fazer algumas operações mais complexas (mudar a cor, por exemplo), tornando tudo muito 
   customizável. No mínimo vão ter essas customizações: mudar a cor do widget quando ativado, a cor do widget quando desativado, a cor de highlight do widget, a cor da borda, o tamanho da 
   borda, o tipo da fonte, a cor da fonte, o tamanho da fonte, a margem entre a fonte e a borda, etc...
 * Ter um sistema que detecta \n em títulos de Widgets e quebre a linha do texto na hora de renderizar, escalando o widget proporcionalmente
 * Talvez ter uma opção para mudar a orientação (centralizado, colado na esquerda ou na direita) do títulos de alguns Widgtes (dos que fizer sentido, como botões, onde você pode escolher um 
   tamanho diferente e deixar o título dele centralizado)
 * Não deixar o usuário setar o tamanho de um Widget como sendo menor do que o tamanho padrão (o que dependo da fonte e da margem), apenas maior
 * Talvez eu precise dar uma distinguida melhor no modelo de alguns dos Widgets que estão muito parecidos (exemplo: o Button, a Progress Bar e a Text Box)
 * Talvez adicionar algumas opções como a de "desativar" um Widget, similar a que tinha no Windows Forms 
 * [Picture Box]: *** ADICIONAR NO FUTURO ***
 * [Color Picker]: *** ADICIONAR NO FUTURO ***
 * [Chart]: *** ADICIONAR NO FUTURO ***
 */

#include "../Source/Widgets/Button.h"
#include "../Source/Widgets/CheckBox.h"
#include "../Source/Widgets/ComboBox.h"
#include "../Source/Widgets/Label.h"
#include "../Source/Widgets/NumericUpDown.h"
#include "../Source/Widgets/ProgrssBar.h"
#include "../Source/Widgets/RadioButton.h"
#include "../Source/Widgets/TextBox.h"

#include "../Source/Color.h"
#include "../Source/Controller.h"
#include "../Source/Event.h"
#include "../Source/Font.h"
#include "../Source/WidgetGroup.h"

#endif