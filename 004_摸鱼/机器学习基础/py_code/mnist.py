import torch
import torchvision
import torchvision.transforms as transforms
import torch.nn as nn
import torch.optim as optim

#定义网络结构
class LeNet(nn.Module):
    def __init__(self):
        super(LeNet, self).__init__()
        self.conv1 = nn.Sequential(  #input_size=(1*28*28)
            nn.Conv2d(in_channels=1, 
                      out_channels=6, 
                      kernel_size=5, 
                      stride=1, 
                      padding=2) , #padding=2保证输入输出尺寸相同
            nn.ReLU(),       #input_size=(6*28*28)
            nn.MaxPool2d(kernel_size=2, stride=2), #output_size=(6*14*14)
        )
        self.conv2 = nn.Sequential(
            nn.Conv2d(6, 16, 5),
            nn.ReLU(),      #input_size=(16*10*10)
            nn.MaxPool2d(kernel_size=2, stride=2)  #output_size=(16*5*5)
        )
        self.fc1 = nn.Sequential(
            nn.Linear(in_features=16 * 5 * 5, 
                      out_features = 120,
                      bias=True),
            nn.ReLU()
        )
        self.fc2 = nn.Sequential(
            nn.Linear(120, 84),
            nn.ReLU()
        )
        self.fc3 = nn.Linear(84, 10)

    # 定义前向传播过程，输入为x   
    def forward(self, x):
        x = self.conv1(x)
        x = self.conv2(x)
        # nn.Linear()的输入输出都是维度为一的值，所以要把多维度的tensor展平成一维
        x = x.view(x.size()[0], -1)
        x = self.fc1(x)
        x = self.fc2(x)
        x = self.fc3(x)
        return x


# 超参数设置
EPOCH = 8   #遍历数据集次数
BATCH_SIZE = 64      #批处理尺寸(batch_size)
LR = 0.001        #学习率

# 定义训练数据集
trainset = torchvision.datasets.MNIST(
    root='./mnist/',
    train=True,
    download=True,
    transform=transforms.ToTensor())
# 定义训练批处理数据
trainloader = torch.utils.data.DataLoader(
    trainset,
    batch_size=BATCH_SIZE,
    shuffle=True,
    )
# 定义测试数据集
testset = torchvision.datasets.MNIST(
    root='./mnist/',
    train=False,
    download=True,
    transform=transforms.ToTensor())

testloader = torch.utils.data.DataLoader(
    testset,
    batch_size=BATCH_SIZE,
    shuffle=False,
    )

net = LeNet().cuda()
# 定义损失函数loss function 和优化方式（采用SGD）
criterion = nn.CrossEntropyLoss()  # 交叉熵损失函数，通常用于多分类问题上
optimizer = optim.SGD(net.parameters(), lr=LR, momentum=0.9)
#optimizer = optim.Adam(net.parameters(), lr=LR, betas=(0.9, 0.999)))

if __name__ == "__main__":
    net.train() # 训练模式
    for epoch in range(EPOCH):
        sum_loss = 0.0
        # 数据读取
        for i, data in enumerate(trainloader):
            inputs, labels = data
            inputs, labels = inputs.cuda(), labels.cuda()
            # 梯度清零
            optimizer.zero_grad()

            # forward + backward
            outputs = net(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
            # 每训练100个batch打印一次平均loss
            sum_loss += loss.item()
            if i % 100 == 99:
                print('[%d, %d] loss: %.03f'
                      % (epoch + 1, i + 1, sum_loss / 100))
                sum_loss = 0.0

    
    net.eval()#测试模式
    correct = 0
    total = 0
    for data in testloader:
        images, labels = data
        images, labels = images.cuda(), labels.cuda()
        outputs = net(images)
        # 取得分最高的那个类
        _, predicted = torch.max(outputs.data, 1)
        total += labels.size(0)
        correct += (predicted == labels).sum()
    print('准确率为: %d%%' % (100 * correct / total))
