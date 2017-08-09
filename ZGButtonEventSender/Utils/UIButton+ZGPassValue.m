//
//  UIButton+ZGPassValue.m
//  ZGButtonEventSender
//
//  Created by offcn_zcz32036 on 2017/8/9.
//  Copyright © 2017年 cn. All rights reserved.
//

#import "UIButton+ZGPassValue.h"
#import <objc/runtime.h>
@implementation UIButton (ZGPassValue)
-(NSDictionary *)paramDic
{
    return objc_getAssociatedObject(self, _cmd);
}
-(void)setParamDic:(NSDictionary *)paramDic
{
    objc_setAssociatedObject(self, @selector(paramDic), paramDic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}
@end
