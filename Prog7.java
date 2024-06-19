package LabPrograms;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class Prog7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter message : ");
        int msg = sc.nextInt();
        System.out.println("p : ");
        int p = sc.nextInt();
        System.out.println("q : ");
        int q = sc.nextInt();
        int n = p*q;
        int z = (p-1)*(q-1);
        System.out.println("The value of z = " + z);
        int e;
        for(e=2;e<z;e++){
            if(gcd(e,z) == 1) break;
        }
        System.out.println("the value of e = " + e);
        int d=0;
        for(int i=0;i<=9;i++){
            int x = 1 + (i*z);
            if(x%e == 0){
                d = x/e;
                break;
            }
        }
        System.out.println("The value of d = " + d);
        double c = (Math.pow(msg,e)) % n;
        System.out.println("Encrypted message is : " + c);
        BigInteger N = BigInteger.valueOf(n);
        BigInteger C = BigDecimal.valueOf(c).toBigInteger();
        BigInteger msgBack = (C.pow(d)).mod(N);
        System.out.println("Decrypted message is : " + msgBack);
    }
    static int gcd(int e,int z){
        if(e==0) return z;
        else return gcd(z%e,e);
    }
}
