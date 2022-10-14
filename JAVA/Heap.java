import java.util.*;

// created a heap data structure
public class Heap {
    private ArrayList<Integer> heap = new ArrayList<>();

    // this is a list of elements which will be inserted in the heap
    public ArrayList<Integer> list = new ArrayList<>();

    Heap(){
        heap.add(-1);
        list.add(-1);
    }

    // this is to insert an element in the heap
    // this is different from heapify because here we choose a child to parent swapping approach
    private void insertion(int data){
        if(heap.isEmpty()){
            heap.add(data);
            return;
        }
        heap.add(data);
        int j = heap.size()-1;
        int i = heap.size()-1;
        while(i>=1){
            i/=2;
            if(heap.get(i)>heap.get(j)){
                Collections.swap(heap, i, j);  
            }
            j=i;
        }
    }

    // this method is used when the root element does not have the correct value
    // and we want to place it in the correct position by swapping its value from the 
    // children values till it reaches the correct place 
    // here it is different from insertion as it follows a parent to child approach swapping approach 
    // its TC: O(logn)
    private void heapify(int data,int i){
        int j = 2*i;
        int k = 2*i+1;
        if(j>=heap.size()&&k>=heap.size()){
            return;
        }
        if(data<heap.get(j)&&data<heap.get(k)){
            return;
        }
        int min = (heap.get(j)>heap.get(k))?k:j;
        Collections.swap(heap, min, i);
        heapify(data, min);
    }

    // we obtain the value of the top most priority element of the heap
    private int top(){
        return heap.get(1);
    }

    // we take out the top most priority element of the heap 
    private void pop(){
        Collections.swap(heap,1,heap.size()-1);
        heap.remove(heap.size()-1);
        heapify(heap.get(1),1);
    }

    // this method is to build the heap from the array of elements
    // it has complexity O(nlogn)
    // this is different from heapify because here we choose a child to parent swapping approach
    private void buildFromArray(){
        int n = list.size();
        for(int i=1;i<n;i++){
            int indx = i;
            int parent = indx/2;
            // here indx>1 and not ind>0 because for 2nd case parent will become 0
            // and swapping will happen for the 0th charater
            while(indx>1 && list.get(indx)>list.get(parent)){
                Collections.swap(list, indx, parent);
                indx = parent;
                parent/=2;
            }
        }
    }

    // building heap from array in TC: O(n) 
    private void buildHeap(){
        int n = list.size();
        for(int i=n/2;i>=1;i--){
            heapify(list.get(i),i);
        }
    }

    // printing the heap elements
    private void print(){
        for(Integer i: heap){
            if(i==-1) continue;
            System.out.print(i+" ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Heap h = new Heap();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while(n!=-1){
            // h.insertion(n);
            h.list.add(n);
            n = sc.nextInt();
        }
        sc.close();
        // h.print();
        // h.insertion(0);
        // h.print();

        // System.out.println("min:"+h.top());
        // h.pop();
        // h.print();
        h.buildHeap();
        for(Integer i:h.list){
            System.out.print(i+" ");
        }
        System.out.println();
    }
}
