
import java.util.ArrayList;
import java.util.List;

public class Solution {

    private static final char[][] strobogrammaticPairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    public List<String> findStrobogrammatic(int targetNumberOfDigits) {
        return findStrobogrammaticNumber(targetNumberOfDigits, targetNumberOfDigits);
    }

    private List<String> findStrobogrammaticNumber(int currentNumberOfDigits, int targetNumberOfDigits) {
        if (currentNumberOfDigits == 0) {
            return new ArrayList<>(List.of(""));
        }
        if (currentNumberOfDigits == 1) {
            return new ArrayList<>(List.of("0", "1", "8"));
        }
        List<String> priorStrobogrammatic = findStrobogrammaticNumber(currentNumberOfDigits - 2, targetNumberOfDigits);
        List<String> currentStrobogrammatic = new ArrayList<>();

        for (final String previous : priorStrobogrammatic) {
            for (final char[] pair : strobogrammaticPairs) {
                if (pair[0] != '0' || currentNumberOfDigits < targetNumberOfDigits) {
                    currentStrobogrammatic.add(pair[0] + previous + pair[1]);
                }
            }
        }
        return currentStrobogrammatic;
    }
}
