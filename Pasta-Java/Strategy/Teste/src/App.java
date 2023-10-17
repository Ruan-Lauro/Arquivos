import java.util.ArrayList;
import java.util.List;

import javax.swing.JOptionPane;

public class App {

    public static void main(String[] args) throws Exception {
        String ax = JOptionPane.showInputDialog("Primeiro número");
        String bx = JOptionPane.showInputDialog("Segundo número");

        Integer a = Integer.parseInt(ax);
        Integer b = Integer.parseInt(bx);

        List<Integer> menu = new ArrayList<>();
        menu.add(1);
        menu.add(2);
        menu.add(3);
        menu.add(4);

        int menuSelecionado = 1;
        while (menu.get(menuSelecionado) != 4) {
            menuSelecionado = verMenu(menu);
            if (menu.get(menuSelecionado) == 1) {
                Context.setStrategy(new ConcreteStrategyAdd());
                int result = Context.executeStrategy(a, b);
                JOptionPane.showMessageDialog(null, "Resultado da soma de "+ a +" por "+ b +" é: " + result);
            } else if (menu.get(menuSelecionado) == 2){
                Context.setStrategy(new ConcreteStrategySubtract());
                int result = Context.executeStrategy(a, b);
                JOptionPane.showMessageDialog(null, "Resultado da subtração de "+ a +" por "+ b +" é: " + result);
            }else if (menu.get(menuSelecionado) == 3){
                Context.setStrategy(new ConcreteStrategyMultiply());
                int result = Context.executeStrategy(a, b);
                JOptionPane.showMessageDialog(null, "Resultado da multiplicação de "+ a +" por "+ b +" é: " + result);
            }

        }

}

    private static int verMenu(List<Integer> menu) {
        Object[] menusArray = menu.toArray();
        int opcaoSelecionad = JOptionPane.showOptionDialog(null,
                "1. Somar \n2. Subtrair \n3. Multiplicar \n4. Sair",
                "Menu",
                JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE, null,
                menusArray, null);
        return opcaoSelecionad;
    }

    
}
