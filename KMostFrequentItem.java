/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author rajeshkumar.yadav
 */

import java.util.*;
import java.io.*;

class Pair{
    
    int key;
    int value;

    public Pair(int a, int b) {
        key = a;
        value = b;
    }
    
    public int getKey() {
        return key;
    }

    public void setKey(int key) {
        this.key = key;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }
    
}

public class KMostFrequentItem {
    
    public static void heapyfy(int index, List<Pair> ans )
    {
        for(int i = index; i>0; i--)
        {
            if(ans.get(i-1).getValue() < ans.get(i).getValue())
                {
                    Pair temp = ans.get(i-1);
                    ans.set(i-1, ans.get(i));
                    ans.set(i, temp);
                }
                else{
                    return;
                }
        }
    }
    
    public static void checkPush(List<Pair> ans, Pair  p, int k)
    {
        for(int i=0; i<ans.size(); i++)
        {
            if(ans.get(i).getKey() == p.getKey())
            {
                ans.set(i, p);
                heapyfy(i, ans);
                return;
                
            }
        }
        
        if(ans.size() < k)
        {
            ans.add(p);
        }else if(ans.get(k-1).getValue() < p.getValue())
        {
            ans.set(k-1, p);
        }else{
            return;
        }
        
        heapyfy(ans.size()-1, ans);
       
    }
    
    public static List<Integer> topKFrequent(int[] nums, int k) 
    {
        Map<Integer, Integer> h  = new HashMap<Integer, Integer>();
        List<Pair> arr;
        arr = new ArrayList<>();
        
        List<Integer> ans = new ArrayList<>();
        
        for(int  i=0 ; i<nums.length; i++)
        {
            int count = 0;
            if(h.get(nums[i]) != null )
            {
                count = h.get(nums[i]);
            }
            count++;
            Pair temp = new Pair(h.get(nums[i]), count);
            checkPush(arr, temp, k);
            h.put(nums[i], count);
        }
        
        for(int i = 0; i<k; i++)
        {
            ans.add(arr.get(i).getValue());
        }
        return ans;
    }
    
    public static void main(String args[])
    {
        int[] arr = new int[3];
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        List<Integer> ans = topKFrequent(arr, 1);
    }
    
}
