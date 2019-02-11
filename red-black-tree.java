package me.iwts;

class RBT<Key extends Comparable<Key>, Value>{
    private static final boolean BLACK = false;
    private static final boolean RED = true;

    private Node root;

    private class Node{
        private Key key;
        private Value value;
        private Node left;
        private Node right;
        private boolean color;

        public Node(Key key,Value value){
            this.key = key;
            this.value = value;
            this.color = RED;
        }
    }

    public Value get(Key key){
        if(key == null) return null;
        return get(this.root,key);
    }
    public Value get(Node root,Key key){
        while(root != null){
            int cmp = key.compareTo(root.key);
            if(cmp == 0) return root.value;
            if(cmp < 0){
                root = root.left;
            }else{
                root = root.right;
            }
        }
        return null;
    }

    public Value min(){
        if(root == null) return null;
        Node temp = min(root);
        return temp.value;
    }
    public Node min(Node root){
        if(root == null) return null;
        while(root.left != null){
            root = root.left;
        }
        return root;
    }

    // 左右旋以及颜色转换
    private boolean isRed(Node node){
        if(node == null) return false;
        return node.color == RED;
    }

    private Node rotateLeft(Node h){
        Node x = h.right;
        h.right = x.left;
        x.left = h;
        x.color = h.color;
        h.color = RED;
        return x;
    }
    private Node rotateRight(Node h){
        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = h.color;
        h.color = RED;
        return x;
    }
    private void flipColors(Node h){
        h.color = !h.color;
        h.left.color = !h.left.color;
        h.right.color = !h.right.color;
    }

    // 平衡算法，非常核心，下面三种情况按顺序跑，控制了红黑树的所有自平衡情况
    private Node balance(Node root){
        if(isRed(root.right)) root = rotateLeft(root);
        if(isRed(root.left) && isRed(root.left.left)) root = rotateRight(root);
        if(isRed(root.left) && isRed(root.right)) flipColors(root);
        return root;
    }

    // 插入
    public void put(Key key,Value value){
        root = put(root,key,value);
        root.color = BLACK;
    }
    private Node put(Node root,Key key,Value value){
        if(root == null) return new Node(key,value);
        int cmp = key.compareTo(root.key);
        if(cmp == 0){
            root.value = value;
        }else{
            if(cmp > 0){
                root.right = put(root.right,key,value);
            }else{
                root.left = put(root.left,key,value);
            }
        }
        if(isRed(root.right) && !isRed(root.left)) root = rotateLeft(root);
        if(isRed(root.left) && isRed(root.left.left)) root = rotateRight(root);
        if(isRed(root.left) && isRed(root.right)) flipColors(root);
        return root;
    }

    // 删除最小值
    private Node moveRedLeft(Node root){
        flipColors(root);
        if(isRed(root.right.left)){
            root.right = rotateRight(root.right);
            root = rotateLeft(root);
            flipColors(root);
        }
        return root;
    }
    public void deleteMin(){
        if(!isRed(root.left) && !isRed(root.right)) root.color = RED;
        root = deleteMin(root);
        if(root != null) root.color = BLACK;
    }
    private Node deleteMin(Node root){
        if(root.left == null) return null;
        if(!isRed(root.left) && !isRed(root.left.left)) root = moveRedLeft(root);
        root.left = deleteMin(root.left);
        return balance(root);
    }

    private Node moveRedRight(Node root){
        flipColors(root);
        if(isRed(root.left.left)){
            root = rotateRight(root);
            flipColors(root);
        }
        return root;
    }
    public void deleteMax(){
        if(!isRed(root.left) && !isRed(root.right)) root.color = RED;
        root = deleteMax(root);
        if(root != null) root.color = BLACK;
    }
    private Node deleteMax(Node root){
        if(isRed(root.left)) root = rotateRight(root);
        if(root.right == null) return null;
        if(!isRed(root.right) && !isRed(root.right.left)) root = moveRedRight(root);
        root.right = deleteMax(root.right);
        return balance(root);
    }

    public void delete(Key key){
        if(!isRed(root.left) && !isRed(root.right)) root.color = RED;
        root = delete(root,key);
        if(root != null) root.color = BLACK;
    }
    private Node delete(Node root,Key key){
        int cmp = key.compareTo(root.key);
        if(cmp < 0){
        	// 左递归，跟删除最小值的一样
            if(!isRed(root.left) && !isRed(root.left.left)) root = moveRedLeft(root);
            root.left = delete(root.left,key);
        }else{
        	// 右递归，先判定了是否需要删除最小值的第一次旋转保证不会丢失左子树
            if(isRed(root.left)) root = rotateRight(root);
            // 找到了，该删了，但是需要确保不会丢失右子树
            if(cmp == 0 && (root.right == null)) return null;
            // 这个是删除最大值中的算法
            if(!isRed(root.right) && !isRed(root.right.left)) root = moveRedRight(root);
            // 此时，完美解决所有丢失情况，可以正常删除了，这个过程实际上就是二叉搜索树树的删除
            if(cmp == 0){
                Node x = min(root.right);
                root.key = x.key;
                root.value = x.value;
                root.right = deleteMin(root.right);
            }else{
                root.right = delete(root.right,key);
            }
        }
        return balance(root);
    }
}

public class Main{
    public static void main(String[] args){
        RBT<String,String> rbt = new RBT<>();
        rbt.put("s","s");
        rbt.put("e","e");
        rbt.put("a","a");
        rbt.put("r","r");
        rbt.put("c","c");
        rbt.put("h","h");
        rbt.put("x","x");
        rbt.put("m","m");
        rbt.put("p","p");
        rbt.put("l","l");
    }
}
