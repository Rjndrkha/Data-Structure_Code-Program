import java.util.Arrays;

public class FinalValueofVariableAfterPerformingOperations {
    public int finalValueAfterOperations(String[] operations) {
        return Arrays.stream(operations).mapToInt(s -> (s.contains("+")) ? 1 : -1).sum();
    }
}