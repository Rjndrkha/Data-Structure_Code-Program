public class Main {

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        list.addLast(40);
        list.addLast(50);
        list.addLast(60);
        list.addLast(70);
        list.addLast(80);

        list.display();
        list.reverse();
        list.display();
        list.reversePtr();
        list.display();
        System.out.println(list.mid());
        list.add(35, 3);
        list.display();

    }

    public static class Node{
        int data;
        Node next;
    }

    public static class LinkedList{
        Node head;
        Node tail;
        int size;

        void addLast(int val){
            Node temp = new Node();
            temp.data = val;
            temp.next = null;

            if(size == 0){
                tail = head = temp;
            }else{
                tail.next = temp;
                tail = temp;
            }

            size++;
        }

        public void addFirst(int value){
            Node temp = new Node();
            temp.data = value;


            if(size == 0){
                temp.next = null;
                head = tail = temp;
            }else{
                temp.next = head;
                head = temp;
            }

            size++;
        }

        public void add(int value, int index){
            Node node = new Node();
            node.data = value;
            if(index < 0 || index > size){
                System.out.println("Invalid Index");
            }
            else if(size == 0){
                addFirst(value);
                size++;
            }else if(index == size){
                addLast(value);
                size++;
            }
            else {
                Node temp = head;
                int i = 0;
                while(i < index - 1){
                    temp = temp.next;
                    i++;
                }
                node.next = temp.next;
                temp.next = node;
                size++;
            }
        }

        public int size(){
            return size;
        }

        public void display(){
            Node temp = head;
            while(temp != null){
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
            System.out.println();
        }

        public void removeFirst(){
            if(size == 0) {
                System.out.println("List is Empty");
            } else if(size == 1){
                head = tail = null;
                size = 0;
            }
            else {
                head = head.next;
                size--;
            }
        }

        public void removeLast(){
            if(size == 0){
                System.out.println("List is Empty");
            }
            else if(size == 1){
                head = tail = null;
                size = 0;
            }
            else{
                Node temp = head;
                for (int i = 0; i < size - 2; i++) {
                    temp = temp.next;
                }
                tail = temp;
                temp.next = null;
                size--;
            }
        }

        public void remove(int index){
            if(index < 0 || index >= size){
                System.out.println("Invalid Index");
            }
            else if(index == size - 1){
                removeLast();
            }
            else if(index == 0){
                removeFirst();
            }
            else {
                Node temp = head;
                for (int i = 0; i < index - 1; i++) {
                    temp = temp.next;

                }
                temp.next = temp.next.next;
                size--;
            }
        }

        public int getValue(int index){
            if(index < 0 || index >= size){
                return -1;
            }
            else if(size == 0){
                return -1;
            }
            else{
                Node temp = head;
                int i = 0;
                while(i < index){
                    temp = temp.next;
                    i++;
                }
                return temp.data;
            }
        }

        public int getFirst(){
            if(size == 0){
                return -1;
            }else{
                return head.data;
            }
        }

        public int getLast(){
            if(size == 0){
                return -1;
            }else{
                return tail.data;
            }
        }

        public Node getNodeAt(int index){
            Node temp = head;
            for(int i = 0; i < index; i++){
                temp = temp.next;
            }
            return temp;
        }

        public void reverse(){
            int first = 0;
            int last = size - 1;

            while(first < last){
                Node left = getNodeAt(first);
                Node right = getNodeAt(last);

                int temp = left.data;
                left.data = right.data;
                right.data = temp;

                first++;
                last--;
            }
        }

        public void reversePtr(){
            Node prev = null;
            Node curr = head;

            while(curr != null){

                Node ocn = curr.next;

                curr.next = prev;
                prev = curr;
                curr = ocn;

            }

            Node temp = head;
            head = tail;
            tail = temp;
        }

        public int mid(){
            Node f = head;
            Node s = head;

            while(f.next != null && f.next.next != null){
                s = s.next;
                f = f.next.next;
            }
            return s.data;
        }
    }


}
