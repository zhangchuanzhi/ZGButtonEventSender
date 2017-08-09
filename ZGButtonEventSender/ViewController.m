//
//  ViewController.m
//  ZGButtonEventSender
//
//  Created by offcn_zcz32036 on 2017/8/9.
//  Copyright © 2017年 cn. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    UIButton *btn=[UIButton wh_buttonWithTitle:@"点我" backColor:[UIColor cyanColor] backImageName:nil titleColor:[UIColor blackColor] fontSize:14 frame:CGRectMake(40, 64+10, 120, 30) cornerRadius:15];
    btn.paramDic=@{@"name":@"小明",@"age":@"27"};
    [self.view addSubview:btn];
    [btn wh_addActionHandler:^{
        NSLog(@"我叫%@,今年%@岁",btn.paramDic[@"name"],btn.paramDic[@"age"]);
        [btn setTitleColor:[UIColor redColor] forState:UIControlStateNormal];//这里只有normal状态正常显示
    }];
}



@end
