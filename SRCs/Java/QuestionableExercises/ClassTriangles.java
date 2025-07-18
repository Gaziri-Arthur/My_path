package QuestionableExercises;
public class ClassTriangles {

    public static String whatTriangle(int a, int b, int c) {
        if (a == b && b == c) {
            return "Equilátero";
        } else if (a == b || a == c || b == c) {
            return "Isósceles";
        } else {
            return "Escaleno";
        }
    }
    public static void isTriangle(int a, int b, int c) {
        if (a + b > c && a + c > b && b + c > a) {
            System.out.println("Os lados formam um triângulo.");
        } else {
            System.out.println("Os lados não formam um triângulo.");
            return;
        }
        whatTriangle(a, b, c);
    }
}
