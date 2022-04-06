abstract class PairMap{
  protected String keyArray [];
  protected String valueArray [];
  abstract String get(String key);
  abstract void put(String key, String value);

  abstract String delete(String key);

  abstract int length();
}

class Dictionary extends PairMap{
  private int length = 0;
  Dictionary(int count){
    keyArray = new String[count]; 
    valueArray = new String[count];
    for(int i =0;i < count; i++) keyArray[i] = "";
  }
  @Override
  String get(String key) {
    int index = 0;
    for(int i = 0; i < keyArray.length; i++){
      if(keyArray[i].equals(key)) index = i;
    }
    return valueArray[index];
  }

  @Override
  void put(String key, String value) {
    length++;
    for(int i =0; i < keyArray.length; i++){
      if(keyArray[i].equals(key)){
        valueArray[i] = value;
        return ;
      }
    }
    keyArray[length] = key;
    valueArray[length] = value;
  }

  @Override 
  String delete(String key){
    String returnValue = null;
    for(int i =0; i < keyArray.length; i++){
      if(keyArray[i].equals(key)){
        length--;
        returnValue = keyArray[i];
        valueArray[i] = null;
        return returnValue; 
      }
    }
    return null;
  }

  @Override
  int length() {
    return length;
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
