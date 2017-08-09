//
//  ZGUtilsMacros.h
//  ZG
//
//  Created by offcn_zcz32036 on 2017/7/6.
//  Copyright © 2017年 cn. All rights reserved.
//

//一些工具宏，比如获取屏幕宽高，系统版本，数据类型验证 自己创建的页面控制器等


#ifndef ZGUtilsMacros_h
#define ZGUtilsMacros_h


//获取系统对象
#define ZG_Application        [UIApplication sharedApplication]
#define ZG_AppWindow          [UIApplication sharedApplication].delegate.window
#define ZG_AppDelegate        [AppDelegate shareAppDelegate]
#define ZG_UserDefaults       [NSUserDefaults standardUserDefaults]
#define ZG_NotificationCenter [NSNotificationCenter defaultCenter]

///IOS 版本判断
#define IOSAVAILABLEVERSION(version) ([[UIDevice currentDevice] availableVersion:version] < 0)
// 当前系统版本
#define CurrentSystemVersion [[UIDevice currentDevice].systemVersion doubleValue]
//当前语言
#define CurrentLanguage (［NSLocale preferredLanguages] objectAtIndex:0])

//-------------------打印日志-------------------------
//DEBUG  模式下打印日志,当前行
#ifdef DEBUG
#define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define DLog(...)
#endif

//拼接字符串
#define ZG_NSStringFormat(format,...) [NSString stringWithFormat:format,##__VA_ARGS__]



//获取屏幕宽高
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREEN_BOUNDS [UIScreen mainScreen].bounds

//同Ip6相对的宽高比
#define ZG_Iphone6ScaleWidth SCREEN_WIDTH/375.0
#define ZG_Iphone6ScaleHeight SCREEN_HEIGHT/667.0

//根据ip6的屏幕来拉伸
#define ZG_RealValue(width) ((width)*(SCREEN_WIDTH/375.0f))


//强弱引用
#define ZG_WeakSelf(type)  __weak typeof(type) weak##type = type;
#define ZG_StrongSelf(type) __strong typeof(type) type = weak##type;

//View 圆角和加边框
#define ViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// View 圆角
#define ViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]

//定义UIImage对象
#define ZG_ImageWithFile(_pointer) [UIImage imageWithContentsOfFile:([[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@@%dx", _pointer, (int)[UIScreen mainScreen].nativeScale] ofType:@"png"])]
#define ZG_IMAGE_NAMED(name) [UIImage imageNamed:name]

//获取一段时间间隔
#define ZG_StartTime CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define ZG_EndTime  NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)

//发送通知
#define ZG_PostNotification(name,obj) [[NSNotificationCenter defaultCenter] postNotificationName:name object:obj];

//单例化一个类
#define ZG_SINGLETON_FOR_HEADER(className) \
\
+ (className *)shared##className;

#define ZG_SINGLETON_FOR_CLASS(className) \
\
+ (className *)shared##className { \
static className *shared##className = nil; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
shared##className = [[self alloc] init]; \
}); \
return shared##className; \
}



#endif 
