#include "SI.h"

int min_max(board br, int max_deep, int deep, int size_, int x, int y)
{
    if(deep > max_deep)
        return 0;

    int sum=0;

     br.set_space(x,y,2);
     if(br.win()==2)
        return 0;
     if(br.win()==-1)
        return 0;

    for(int i=0; i<size_;i++)
    {
        for(int j=0; j<size_;j++)
        {
            if(br.get_space(i,j)==0)
            {
                br.set_space(i,j,1);
                if(br.win()==1)
                    return 1;
                if(br.win()==-1)
                    return 0;

                for(int k=0; k<size_;k++)
                    for(int l=0; l<size_;l++)
                        if(br.get_space(k,l)==0)
                            sum+=min_max(br, max_deep, deep+1, size_, k, l);
            }
        }
    }

    return sum;
}

void SI(board br ,int size_ ,int win_c ,int max_deep)
{
    move_ best_m;
    best_m.value=100;
    for(int i=0; i<size_;i++)
        for(int j=0; j<size_;j++)
        {
            int value;
            board copy_;
            copy_.init(size_,win_c);
            for(int k=0; k<size_;k++)
                for(int l=0; l<size_;l++)
                    copy_.set_space(k,l,br.get_space(k,l));
            if(br.get_space(i,j)==0)
            {
                value = min_max(copy_, max_deep, 1, size_, i, j);
                if(value<best_m.value)
                {
                    best_m.value=value;
                    best_m.x=i;
                    best_m.y=j;
                }
            }
        }
    br.set_space(best_m.x, best_m.y, 2);
}
