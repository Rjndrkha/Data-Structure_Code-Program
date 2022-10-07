import torch 
import torch.nn as nn
import torch.nn.functional as F
from torchsummary import summary 


class ResConvBlock(nn.Module):
    def __init__(self, filter, kernel=3):
        super(ResConvBlock, self).__init__()
        self.conv1 = nn.Conv2d(filter, filter, kernel)
        self.conv2 = nn.Conv2d(filter, filter, kernel)
        self.pad = nn.ZeroPad2d(1)
        self.pool = nn.MaxPool2d(2,2)
        self.norm1 = nn.BatchNorm2d(filter)
        self.norm2 = nn.BatchNorm2d(filter)
        self.lrelu = nn.LeakyReLU(0.1)

    def forward(self, x):
        s = x
        x = self.lrelu(self.norm1(self.pad(self.conv1(x))))
        x = self.lrelu(self.norm2(self.pad(self.conv2(x)))+s)
        return x

class ResBottleNeck(nn.Module):
    def __init__(self, infilter, outfilter, kernel=3):
        super(ResBottleNeck, self).__init__()
        self.conv1 = nn.Conv2d(infilter, infilter, kernel)
        self.conv2 = nn.Conv2d(infilter, outfilter, 1)
        self.conv0 = nn.Conv2d(infilter, infilter, 1, stride=2)
        self.conv = nn.Conv2d(infilter, outfilter, 1, stride=2)
        self.pad = nn.ZeroPad2d(1)
        self.norm0 = nn.BatchNorm2d(infilter)
        self.norm1 = nn.BatchNorm2d(infilter)
        self.norm2 = nn.BatchNorm2d(outfilter)
        self.norm = nn.BatchNorm2d(outfilter)
        self.lrelu = nn.LeakyReLU(0.1)
        # self.pool = nn.MaxPool2d(2,2)

    def forward(self, x):
        s = x
        x = self.lrelu(self.norm0(self.conv0(x)))
        x = self.lrelu(self.norm1(self.pad(self.conv1(x))))
        x = self.lrelu(self.norm2(self.conv2(x)))
        s = self.lrelu(self.norm(self.conv(s)))
        x = x+s
        return x

class ResBlock(nn.Module):
    def __init__(self, infilter, outfilter, kernel=3):
        super(ResBlock, self).__init__()
        self.conv0 = ResConvBlock(infilter)
        self.conv1 = ResConvBlock(infilter)

        self.conv = ResBottleNeck(infilter, outfilter)

    def forward(self, x):
        return self.conv(self.conv1(self.conv0(x)))

class StartBlock(nn.Module):
    def __init__(self, filter):
        super(StartBlock, self).__init__()
        self.conv1 = nn.Conv2d(3, filter, 7, stride=2)
        # self.conv2 = nn.Conv2d(filter//2, filter, 5, stride=2)

        self.norm1 = nn.BatchNorm2d(filter)
        # self.norm2 = nn.BatchNorm2d(filter)

        self.lrelu = nn.LeakyReLU(0.1)

    def forward(self, x):
        x = self.lrelu(self.norm1(self.conv1(x)))
        return x #self.lrelu(self.norm2(self.conv2(x)))


class GMaxpool(nn.Module):
    def forward(self, x):
        return F.avg_pool2d(x, kernel_size=x.size()[2:])

# class DenseBlock(nn.Module):
#     def __init__(self, idim, ndim=256, outclass=16):
#         super(DenseBlock, self).__init__()
#         self.dense1 = nn.Linear(idim, ndim)
#         self.dense2 = nn.Linear(ndim, outclass)
#         self.drop = nn.Dropout2d(0.2)
#         self.lrelu = nn.LeakyReLU(0.2)
#         self.softmax = nn.Softmax()


class ResNet(nn.Module):
    def __init__(self, filter=16, ndim=256, outclass=16):
        super(ResNet, self).__init__()
        self.res0 = StartBlock(filter)
        self.res1 = ResBlock(filter, filter*2)
        self.res2 = ResBlock(filter*2, filter*4)
        self.res3 = ResBlock(filter*4, filter*8)
        self.res4 = ResBlock(filter*8, filter*16)
        self.res5 = ResBlock(filter*16, filter*32)
        self.res6 = ResBlock(filter*32, filter*64)

        self.avgpool = GMaxpool()
        self.flat = nn.Flatten()

        self.dense1 = nn.Linear(1024, ndim)
        self.dense2 = nn.Linear(ndim, outclass)
        self.drop = nn.Dropout2d(0.2)
        self.lrelu = nn.LeakyReLU(0.2)
        self.softmax = nn.Softmax()

    def forward(self, x):
        x = self.res6(self.res5(self.res4(self.res3(self.res2(self.res1(self.res0(x)))))))
        x = self.flat(self.avgpool(x))
        return self.softmax(self.dense2(self.lrelu(self.drop(self.dense1(x)))))

model = ResNet()
summary(model, (3, 750,1000))

