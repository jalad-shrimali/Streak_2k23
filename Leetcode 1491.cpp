class Solution {
public:
    double average(vector<int>& salary) {
        int n= salary.size();
        double min= DBL_MAX;
        double max=DBL_MIN;
        double sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=salary[i];
            if(salary[i]<min)min= salary[i];
            if(salary[i]>max)max= salary[i];
        }
        return (sum-min-max)/(n-2);
    }
};
