public class Hello {
    public static void main(String[] args) {
        // System.out.println("hello, i am back");
        int[] array = {1, 2, 3};
        System.out.println(bSearch(array, 3));
        System.out.println(bSearchRecursive(array, 3, 0, 2));
    }

    public static int bSearch(int[] array, int key) {
        int lower = 0, upper = array.length - 1;
        while(lower < upper) {
            int mid = (lower + upper) / 2;
            if(array[mid] == key) return mid;
            if(array[mid] > key) {
                upper = mid - 1;
            } else lower = mid + 1;
        }

        return (array[lower] == key) ? lower : -1;
    }

    public static int bSearchRecursive(int[] array, int key, int lower, int upper) {
        if(lower > upper) return -1;
        int mid = (lower + upper) / 2;
        if(array[mid] == key) return mid;
        if(array[mid] > key) return bSearchRecursive(array, key, lower, mid - 1);
        return bSearchRecursive(array, key, mid + 1, upper);
    }
}
