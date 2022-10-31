public class Tree {
    public Tree(Tree leftChild, Tree rightChild){
        this.leftChild = leftChild;
        this.rightChild = rightChild;
    }

    public static void preOrder(Tree root){
        System.out.print(root.data+" ");
        if(root.leftChild != null){
            preOrder(root.leftChild);
        }
        if(root.rightChild != null){
            preOrder(root.rightChild);
        }
    }

    public Tree getLeftChild(){
        return this.leftChild;
    }

    public Tree getRightChild(){
        return this.rightChild;
    }

    public void setLeftChild(Tree leftChild){
        this.leftChild = leftChild;
    }

    public void setRightChild(Tree rightChild){
        this.rightChild = rightChild;
    }

    public void setData(int data){
        this.data = data;
    }

    public int getData(){
        return this.data;
    }

    private Tree leftChild;
    private Tree rightChild;
    private int data;

    public static void main(String[] args){
        Tree node1 = new Tree(null, null);
        node1.setData(1);
        Tree node2 = new Tree(null, null);
        node2.setData(2);
        node1.setLeftChild(node2);
        Tree node3 = new Tree(null, null);
        node3.setData(3);
        node1.setRightChild(node3);
        Tree node4 = new Tree(null, null);
        node4.setData(4);
        node2.setLeftChild(node4);
        Tree node5 = new Tree(null, null);
        node5.setData(5);
        node3.setLeftChild(node5);
        Tree node6 = new Tree(null, null);
        node6.setData(6);
        node3.setRightChild(node6);

        preOrder(node1);

    }
}
