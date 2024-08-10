struct item {
    int sum;
};
struct segtree {
    int size;
    vector <item> values;

    item NEUTRAL_ELEMENT={0}; //CHANGE THIS

    item merge(item a,item b) {
        return {a.sum+b.sum}; //CHANGE THIS
    }

    item single(int v) {
        return {v}; //CHANGE THIS
    }

    segtree(vector <int> &temp) {
        init(temp.size());
        build(temp);
    }
    void init(int n) {
        size=1;
        while(size<n)size*=2;
        values.resize(2*size);
    }

    void build(vector <int> &a,int x,int lx,int rx) {
        if(lx==rx) {
            if(lx<(int)a.size())
            values[x]=single(a[lx]);
            return;
        }
        int mid=(lx+rx)/2;
        build(a,2*x+1,lx,mid);
        build(a,2*x+2,mid+1,rx);
        values[x]=merge(values[2*x+1],values[2*x+2]);
    }
    void build(vector <int> &a) {
        build(a,0,0,size-1);
    }
    void set(int i,int v,int x,int lx,int rx) {
        if(lx==rx) {
            values[x]=single(v);
            return;
        }
        int mid=(lx+rx)/2;
        if(i<=mid)
        set(i,v,2*x+1,lx,mid);
        else
        set(i,v,2*x+2,mid+1,rx);

        values[x]=merge(values[2*x+1],values[2*x+2]);
    } 
    void set(int i,int v) {
        set(i,v,0,0,size-1);
    }
    int calc(int x,int lx,int rx,int l,int r) { //CHANGE THIS
        if(lx>r || l>rx)return 0;
        else if(lx>=l && rx<=r)return values[x].sum;
        int mid=(lx+rx)/2;
        int a=calc(2*x+1,lx,mid,l,r);
        int b=calc(2*x+2,mid+1,rx,l,r);
        return a+b;
    }
    int calc(int l,int r) { //CHANGE THIS
        return calc(0,0,size-1,l,r);
    }
        
};
