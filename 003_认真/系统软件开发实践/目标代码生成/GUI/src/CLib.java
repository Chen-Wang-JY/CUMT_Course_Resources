import com.sun.jna.Library;
import com.sun.jna.Native;

public interface CLib extends Library{
    String path = "D:\\Here\\recently\\系统软件开发实践\\目标代码生成\\GUI\\src\\resource\\libCodeGenerate.dll";
    CLib lib = (CLib) Native.load(CLib.path, CLib.class);
    void getFourvarcode(String file_name);

}
