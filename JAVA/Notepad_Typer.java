
import java.awt.*;
import java.awt.event.KeyEvent;
import java.io.IOException;


public class Notepad_Typer{
public static void main (String[]args) throws IOException, InterruptedException, AWTException{
    Runtime.getRuntime().exec("notepad.exe");

    Thread.sleep(2000); // 2 sec 
    Robot r=new Robot();
    
    r.keyPress(KeyEvent.VK_H);
    Thread.sleep(500);
    r.keyPress(KeyEvent.VK_E);
    Thread.sleep(500);
    r.keyPress(KeyEvent.VK_L);
    Thread.sleep(500);
    r.keyPress(KeyEvent.VK_L);
    Thread.sleep(500);
    r.keyPress(KeyEvent.VK_O);
    Thread.sleep(500);
    r.keyPress(KeyEvent.VK_SPACE); // displays a whitespace
    Thread.sleep(500);
    r.keyPress(KeyEvent.VK_W);
    Thread.sleep(500);
    r.keyPress(KeyEvent.VK_O);
    Thread.sleep(500);
    r.keyPress(KeyEvent.VK_R);
    Thread.sleep(500);
    r.keyPress(KeyEvent.VK_L);
    Thread.sleep(500);
    r.keyPress(KeyEvent.VK_D);
    // hello world 

    }
}   
