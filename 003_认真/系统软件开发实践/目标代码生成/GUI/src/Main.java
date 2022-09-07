import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import javax.swing.*;
import javax.swing.border.*;
import javax.swing.text.ChangedCharSetException;

import com.sun.jna.Native;
import net.miginfocom.swing.*;
/*
 * Created by JFormDesigner on Sun Mar 27 19:44:34 GMT+08:00 2022
 */



/**
 * @author unknown
 */
public class Main extends JFrame {
    public Main() {
        initComponents();
    }

    private void initComponents() {
        // JFormDesigner - Component initialization - DO NOT MODIFY  //GEN-BEGIN:initComponents
        // Generated using JFormDesigner Evaluation license - Chen Wang
        dialogPane = new JPanel();
        contentPanel = new JPanel();
        labelFilePath = new JLabel();
        buttonSelectFile = new JButton();
        buttonFileClear = new JButton();
        textCodeArea = new JTextArea();
        textAnsArea = new JTextArea();
        buttonLexicalAnalysis = new JButton();
        buttonGrammaticalAnalysis = new JButton();
        buttonTacGenerate = new JButton();
        buttonFinalCodeGenerate = new JButton();

        //======== this ========
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        var contentPane = getContentPane();
        contentPane.setLayout(new BorderLayout());

        //======== dialogPane ========
        {
            dialogPane.setBorder (new javax. swing. border. CompoundBorder( new javax .swing .border .TitledBorder (new javax. swing. border. EmptyBorder( 0
            , 0, 0, 0) , "JFor\u006dDesi\u0067ner \u0045valu\u0061tion", javax. swing. border. TitledBorder. CENTER, javax. swing. border. TitledBorder. BOTTOM
            , new java .awt .Font ("Dia\u006cog" ,java .awt .Font .BOLD ,12 ), java. awt. Color. red) ,
            dialogPane. getBorder( )) ); dialogPane. addPropertyChangeListener (new java. beans. PropertyChangeListener( ){ @Override public void propertyChange (java .beans .PropertyChangeEvent e
            ) {if ("bord\u0065r" .equals (e .getPropertyName () )) throw new RuntimeException( ); }} );
            dialogPane.setLayout(new BorderLayout());

            //======== contentPanel ========
            {
                contentPanel.setLayout(new MigLayout(
                    "insets dialog,hidemode 3",
                    // columns
                    "[200,fill]" +
                    "[200,fill]" +
                    "[200,fill]" +
                    "[200,fill]",
                    // rows
                    "[60]" +
                    "[30]" +
                    "[30]" +
                    "[30]" +
                    "[510]" +
                    "[]"));

                //---- labelFilePath ----
                labelFilePath.setBorder(new MatteBorder(1, 1, 1, 1, Color.black));
                labelFilePath.setText(" ");
                labelFilePath.setFont(labelFilePath.getFont().deriveFont(Font.BOLD|Font.ITALIC, labelFilePath.getFont().getSize() + 7f));
                contentPanel.add(labelFilePath, "cell 0 0 2 1,wmin 200,hmin 40");

                //---- buttonSelectFile ----
                buttonSelectFile.setText("\u9009\u62e9\u6587\u4ef6");
                contentPanel.add(buttonSelectFile, "cell 2 0,wmin 40");

                //---- buttonFileClear ----
                buttonFileClear.setText("\u6e05\u7a7a\u533a\u57df");
                contentPanel.add(buttonFileClear, "cell 3 0,wmin 40");

                //---- textCodeArea ----
                textCodeArea.setFont(new Font("Monospac821 BT", Font.PLAIN, 16));
                contentPanel.add(textCodeArea, "cell 0 1 2 4,wmin 200,hmin 580");

                //---- textAnsArea ----
                textAnsArea.setFont(new Font("\u5b8b\u4f53", Font.PLAIN, 14));
                contentPanel.add(textAnsArea, "cell 2 1 2 4,hmin 580");

                //---- buttonLexicalAnalysis ----
                buttonLexicalAnalysis.setText("\u8bcd\u6cd5\u5206\u6790");
                contentPanel.add(buttonLexicalAnalysis, "cell 0 5");

                //---- buttonGrammaticalAnalysis ----
                buttonGrammaticalAnalysis.setText("\u8bed\u6cd5\u5206\u6790");
                contentPanel.add(buttonGrammaticalAnalysis, "cell 1 5");

                //---- buttonTacGenerate ----
                buttonTacGenerate.setText("\u4e2d\u95f4\u4ee3\u7801");
                contentPanel.add(buttonTacGenerate, "cell 2 5");

                //---- buttonFinalCodeGenerate ----
                buttonFinalCodeGenerate.setText("\u76ee\u6807\u4ee3\u7801");
                contentPanel.add(buttonFinalCodeGenerate, "cell 3 5");
            }
            dialogPane.add(contentPanel, BorderLayout.CENTER);
        }
        contentPane.add(dialogPane, BorderLayout.CENTER);
        pack();
        setLocationRelativeTo(getOwner());
        // JFormDesigner - End of component initialization  //GEN-END:initComponents
    }

    // JFormDesigner - Variables declaration - DO NOT MODIFY  //GEN-BEGIN:variables
    // Generated using JFormDesigner Evaluation license - Chen Wang
    private JPanel dialogPane;
    private JPanel contentPanel;
    private JLabel labelFilePath;
    private JButton buttonSelectFile;
    private JButton buttonFileClear;
    private JTextArea textCodeArea;
    private JTextArea textAnsArea;
    private JButton buttonLexicalAnalysis;
    private JButton buttonGrammaticalAnalysis;
    private JButton buttonTacGenerate;
    private JButton buttonFinalCodeGenerate;
    // JFormDesigner - End of variables declaration  //GEN-END:variables

    public void initEvents(){
        buttonSelectFile_Clicked();
        buttonFileClear_Clicked();

        buttonFinalCodeGenerate_Clicked();
    }



    File currentFile;


    /**
     * "选择文件"按钮事件
     */
    private void buttonSelectFile_Clicked(){
        buttonSelectFile.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                File initFile = new File("./");
                JFileChooser jfc=new JFileChooser(initFile);
                jfc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES );
                jfc.showDialog(new JLabel(), "选择");
                currentFile = jfc.getSelectedFile();

                if(currentFile.isFile()){
                    makeFileOnTheScreen(currentFile, 0);
                }
                labelFilePath.setText(currentFile.getAbsolutePath());
            }
        });
    }

    /**
     * "清空区域“按钮事件
     */
    private void buttonFileClear_Clicked(){
        buttonFileClear.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                labelFilePath.setText(" ");
            }
        });
    }

    /**
     * "目标代码"事件
     */
    private void buttonFinalCodeGenerate_Clicked(){
        buttonFinalCodeGenerate.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                go();
                makeFileOnTheScreen(new File("./output/x86.asm"), 1);
            }
        });
    }

    private void go(){
        try {
            String path = new String(currentFile.getCanonicalPath().getBytes(StandardCharsets.UTF_8));
            CLib.lib.getFourvarcode(currentFile.getCanonicalPath());
        } catch (Exception e) {
            System.out.println("Error！");
        }
    }

    private void makeFileOnTheScreen(File file, int flag){
        JTextArea temp = textCodeArea;
        if(flag == 1) {
            temp = textAnsArea;
            textAnsArea.setText("");
        }
        try {
            BufferedReader inputTxt = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
            while(inputTxt.ready()){
                temp.append(inputTxt.readLine() + "\n");
            }
        } catch (Exception ee){}
    }
}
