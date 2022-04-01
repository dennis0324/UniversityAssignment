public class Concert {
    private String hallName;
    private Group[] groups = new Group[3];
    Concert(String hallName){
        this.hallName = hallName;
        groups[0] = new Group('S',10);
        groups[1] = new Group('A',10);
        groups[2] = new Group('B',10);

    }

    public String getHallName() {
        return hallName;
    }

    // public String getHallGroup(){


    // }
}
