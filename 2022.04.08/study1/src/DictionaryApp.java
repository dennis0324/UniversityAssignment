abstract class PairMap{
    protected String keyArray[];
    protected String valueArray[];
    abstract String get(String key);
    abstract void put(String key, String value);
    abstract String delete(String key);
    abstract int length();
}

class Dictionary extends PairMap{
    private int count;
    public Dictionary(int capacity){
        keyArray = new String[capacity];
        valueArray = new String[capacity];
    }

    @Override
    String get(String key){
        for (int i =0; i < count; i++){
            if(keyArray[i].equals(key))
                return valueArray[i];
        }
        return null;
    }

    @Override
    void put(String key,String value){
        int i =0;
        for(i = 0; i <count; i++){
            if( keyArray[i].equals(key))
                break;
        }
        if(i == count) { //key 가 dictionary에 존재하지 않음
            keyArray[i] = key;
            valueArray[i] = value;
            count++;
        }
        else{
            keyArray[i] =key;
            valueArray[i] = value;
        }
    }
    @Override
    String delete(String key) {
        int i = 0;
        for(i = 0;i < count; i++){
            if(keyArray[i].equals(key))
                break;
        }

        if (i == count){
            return null;
        }
        String value = valueArray[i];

        int last = count - 1;
        for (int j = i; j < last; j++){
            keyArray[j] = keyArray[j+1];
        }
        count--;

        return value;
    }

    @Override
    int length() {
        return count;
    }
}

public class DictionaryApp {
    public static void main(String[] args){
        Dictionary dic = new Dictionary(10);
        dic.put("황기태","자바");
        dic.put("이재문","파이선");
        dic.put("이재문","C++");
        System.out.println("이재문의 값은 " + dic.get("이재문"));
        System.out.println("황기태의 값은 " + dic.get("황기태"));
    
        dic.delete("황기태");
        System.out.println("황기태의 값은 " + dic.get("황기태"));
    }
}
