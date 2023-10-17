public class Context {
    private static Strategy Strategy;

    static void setStrategy(Strategy strategy){
        Strategy = strategy;
    }

    static int executeStrategy(int a, int b){
        return Strategy.execute(a, b); 
    }
}
