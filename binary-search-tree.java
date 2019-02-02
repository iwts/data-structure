package me.iwts;

class BST<Key extends Comparable<Key>, Value>{
    private Node root;

    private class Node{
        private Key key;
        private Value value;
        private Node left;
        private Node right;
        private Node father;

        public Node(Key key,Value value){
            this.key = key;
            this.value = value;
        }
    }

//    递归方法进行搜索
//    public Value get(Key key){
//        if(key == null) return null;
//        return get(this.root,key);
//    }
//    public Value get(Node root,Key key){
//        if(root == null) return null;
//        int cmp = key.compareTo(root.key);
//        if(cmp == 0){
//            return root.value;
//        }else{
//            if(cmp < 0){
//                return get(root.left,key);
//            }else{
//                return get(root.right,key);
//            }
//        }
//    }

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

    public Value max(){
        if(root == null) return null;
        Node temp = max(root);
        return temp.value;
    }
    public Node max(Node root){
        if(root == null) return null;
        while(root.right != null){
            root = root.right;
        }
        return root;
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

    public Value floor(Key key){
        if(root == null || key == null) return null;
        return floor(root,key);
    }
    public Value floor(Node root,Key key){
        Value res = null;
        while(root != null){
            int cmp = key.compareTo(root.key);
            if(cmp == 0) return root.value;
            if(cmp < 0){
                root = root.left;
            }else{
                res = root.value;
                root = root.right;
            }
        }
        return res;
    }

    public Value ceiling(Key key){
        if(root == null || key == null) return null;
        return ceiling(root,key);
    }
    public Value ceiling(Node root,Key key){
        Value res = null;
        while(root != null){
            int cmp = key.compareTo(root.key);
            if(cmp == 0) return root.value;
            if(cmp < 0){
                root = root.left;
                root = root.left;
            }else{
                res = root.value;
            }
        }
        return res;
    }

    public void put(Key key,Value value){
        if(key == null || value == null) return;
        if(root == null){
            root = new Node(key,value);
            return;
        }
        put(root,key,value);
    }
    public void put(Node root,Key key,Value value){
        while(root != null){
            int cmp = key.compareTo(root.key);
            if(cmp == 0){
                root.value = value;
                return;
            }
            if(cmp < 0){
                if(root.left == null){
                    root.left = new Node(key,value);
                    root.left.father = root;
                    return;
                }else{
                    root = root.left;
                }
            }else{
                if(root.right == null){
                    root.right = new Node(key,value);
                    root.right.father = root;
                    return;
                }else{
                    root = root.right;
                }
            }
        }
    }
    
    public void deleteMin(){
        deleteMin(root);
    }
    public void deleteMin(Node root){
        Node res = min(root);
        if(res.father == null){
            this.root = null;
        }else{
            if(res.father.left.key.compareTo(res.key) == 0){
                res.father.left = res.right;
            }else{
                res.father.right = res.right;
            }
        }
    }

    public void deleteMax(){
        deleteMax(root);
    }
    public void deleteMax(Node root){
        Node res = max(root);
        if(res.father == null){
            this.root = null;
        }else{
            if(res.father.left.key.compareTo(res.key) == 0){
                res.father.left = res.left;
            }else{
                res.father.right = res.left;
            }
        }
    }

    public void delete(Key key){
        if(key == null) return;
        // 删除根的情况，需要额外处理
        if(key.compareTo(root.key) == 0){
            if(root.left == null && root.right == null){
                root = null;
            }else{
                if(root.left != null && root.right != null){
                    Node temp = min(root.right);
                    deleteMin(root.right);
                    temp.left = root.left;
                    temp.right = root.right;
                    root = temp;
                }else{
                    if(root.left == null){
                        root = root.right;
                    }else{
                        root = root.left;
                    }
                }
            }
        }else{
            // 其他情况
            delete(root,key);
        }
    }
    public void delete(Node root,Key key){
        // flag处理方向，父结点是从左子树连接下来还是右子树
        int flag = 0;
        while(root != null){
            int cmp = key.compareTo(root.key);
            if(cmp == 0){
                Node father = root.father;
                if(root.left == null && root.right == null){
                    if(flag == 1){
                        father.left = null;
                    }else{
                        father.right = null;
                    }
                }else{
                    // 核心算法部分
                    if(root.left != null && root.right != null){
                        // 找右子树最小结点
                        Node temp = min(root.right);
                        deleteMin(root.right);
                        temp.left = root.left;
                        temp.right = root.right;
                        temp.father = root.father;
                        if(flag == 1){
                            father.left = temp;
                        }else{
                            father.right = temp;
                        }
                    }else{
                        if(root.left == null){
                            if(flag == 1){
                                father.left = root.right;
                            }else{
                                father.right = root.right;
                            }
                            root.right.father = father;
                        }else{
                            if(flag == 1){
                                father.left = root.left;
                            }else{
                                father.right = root.left;
                            }
                            root.left.father = father;
                        }
                    }
                }
                return;
            }else{
                if(cmp < 0){
                    root = root.left;
                    flag = 1;
                }else{
                    root = root.right;
                    flag = 2;
                }
            }
        }
    }
}

public class Main{
    public static void main(String[] args){
        BST<String,String> bst = new BST<>();
        bst.put("s","s");
        bst.put("e","e");
        bst.put("a","a");
        bst.put("c","c");
        bst.put("r","r");
        bst.put("h","h");
        bst.put("m","m");
        bst.put("x","x");
        bst.delete("e");
        System.out.println(bst.min());
    }
}
