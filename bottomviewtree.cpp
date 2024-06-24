class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        //step1: create a vector<int> ans
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        //create a queue in which there is a pair of frontnode and hd
        queue< pair<Node* , int> > q;
        q.push(make_pair(root,0));
        //create a one to one mapping of topNode
        map<int,int> topNode;
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            //check if mapping is empty then insert the value of frontnode in it
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
            
        }
        
        for(auto i:topNode){
            ans.push_back(i.second);
        }
        return ans;
        
    }

};
