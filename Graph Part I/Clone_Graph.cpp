#include<bits/stdc++.h>
using namespace std;
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
void clonetheGraph(graphNode* node,vector<graphNode*>& visited)
{
    graphNode* curr=visited[node->data];
    for(auto it:node->neighbours)
    {
        if(visited[it->data]==NULL)
        {
            graphNode* adj=new graphNode(it->data);
            visited[it->data]=adj;
            curr->neighbours.push_back(adj);
            clonetheGraph(it,visited);
        }
        else
        curr->neighbours.push_back(visited[it->data]);
    }
}
graphNode *cloneGraph(graphNode *node)
{
    if(node==NULL)
        return NULL;
    vector<graphNode*> visited(100001,NULL);
    graphNode* root=new graphNode(node->data);
    visited[node->data]=root;
    clonetheGraph(node,visited);
    return root;
}