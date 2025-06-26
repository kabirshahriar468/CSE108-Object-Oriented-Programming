import java.util.Vector;

public class Merchant {
    public Vector<Customer> custom=new Vector<Customer>();

    public void addCustomder(Customer customer){
        custom.add(customer);
    }

    public void searchCustomer(int id){
        for(int i=0;i<custom.size();i++)
        {
            if(custom.get(i).getId()==id)
            {
                System.out.printf("ID: " + custom.get(i).getName());
            }

        }
    }

    public void deleteCustomer(int id){
        for(int i=0;i<custom.size();i++)
        {
            if(custom.get(i).getId()==id)
            {
                custom.remove(i);
            }
        }
    }

}
