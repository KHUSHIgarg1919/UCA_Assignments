class multiply_strings {
    public static String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")){              //return "0" is either from num1 or num2 is 0
            return "0";
        }
        int result[] = new int[num1.length()+num2.length()];      //result arr is made to store the ans.Maximum length of the product can be the sum of the lengths of the multiplicands(num1 and num2)

        //iterate each digit of num1 and num2(start loop from end as multiplication occurs from end)
        for(int i=num1.length()-1;i>=0;i--){                       
            for(int j=num2.length()-1;j>=0;j--){                   
                int product = (num1.charAt(i)-'0')*(num2.charAt(j)-'0');       //multiply two nos.
                result[i+j+1] = result[i+j+1] + product;                       //store in result array at ending position 
                result[i+j] = result[i+j] + result[i+j+1]/10;                  //dividing by 10 gives carry,save carry at previous index of result array 
                result[i+j+1] = result[i+j+1]%10;                              //modulus by 10 gives unit digit that stores at its correct position
            }
        }
        int i = 0;
        StringBuilder ans = new StringBuilder();
        while(i<result.length && result[i] == 0){            //to skip 0's at the beginning
            i++;
        }
        while(i<result.length){        
            ans.append(result[i++]);                         //append result in string ans
        }
        return ans.toString();                               //convert stringbuilder to string
    }
    public static void main(String[] args) {
        String num1 = "2";
        String num2 = "3";
        System.out.println(multiply(num1, num2));
    }
}
