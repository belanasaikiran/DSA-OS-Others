import java.util.ArrayList;
import java.util.List;

class Permu {

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> resultList = new ArrayList<>();

        backtrack(resultList, new ArrayList<>(), nums);
        return resultList;
    }

    private void backtrack(
        List<List<Integer>> resultList,
        ArrayList<Integer> tempList,
        int[] nums
    ) {
        //  if we match the length, it is a permutation
        if (tempList.size() == nums.length) {
            resultList.add(new ArrayList<>(tempList));
        }

        for (int number : nums) {
            // skip if same element
            if (tempList.contains(number)) continue;

            // Add new element
            tempList.add(number);

            // go back and try otjer element
            backtrack(resultList, tempList, nums);

            // Remove the element
            tempList.remove(tempList.size() - 1);
        }
    }
}

public class Permutations {

    public static void main(String[] args) {
        Permu Permutations = new Permu();
        int[] nums = { 1, 2, 3 };
        Permutations.permute(nums);
    }
}
