//
//  JZStackedView.h
//  3D Stacked View
//
//  Created by James Zammit on 26/06/2015.
//  Copyright (c) 2015 James Zammit. All rights reserved.
//

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wobjc-missing-property-synthesis"


#import <Availability.h>
#undef weak_delegate
#undef __weak_delegate
#if __has_feature(objc_arc) && __has_feature(objc_arc_weak) && \
(!(defined __MAC_OS_X_VERSION_MIN_REQUIRED) || \
__MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_8)
#define weak_delegate weak
#else
#define weak_delegate unsafe_unretained
#endif


#import <QuartzCore/QuartzCore.h>
#if defined USING_CHAMELEON || defined __IPHONE_OS_VERSION_MAX_ALLOWED
#define JZ_IOS
#else
#define JZ_MACOS
#endif


#ifdef JZ_IOS
#import <UIKit/UIKit.h>
#else
#import <Cocoa/Cocoa.h>
typedef NSView UIView;
#endif


typedef NS_ENUM(NSInteger, JZType)
{
    JZTypeTimeMachine
    
};


typedef NS_ENUM(NSInteger, JZOption)
{
    JZOptionWrap = 0,
    JZOptionShowBackfaces,
    JZOptionOffsetMultiplier,
    JZOptionVisibleItems,
    JZOptionCount,
    JZOptionArc,
    JZOptionAngle,
    JZOptionRadius,
    JZOptionTilt,
    JZOptionSpacing,
    JZOptionFadeMin,
    JZOptionFadeMax,
    JZOptionFadeRange,
    JZOptionFadeMinAlpha
};


@protocol JZDataSource, JZDelegate;

@interface JZ : UIView

@property (nonatomic, weak_delegate) IBOutlet id<JZDataSource> dataSource;
@property (nonatomic, weak_delegate) IBOutlet id<JZDelegate> delegate;
@property (nonatomic, assign) CGFloat perspective;
@property (nonatomic, assign) CGFloat decelerationRate;
@property (nonatomic, assign) CGFloat scrollSpeed;
@property (nonatomic, assign) CGFloat bounceDistance;
@property (nonatomic, assign, getter = isScrollEnabled) BOOL scrollEnabled;
@property (nonatomic, assign, getter = isPagingEnabled) BOOL pagingEnabled;
@property (nonatomic, assign, getter = isVertical) BOOL vertical;
@property (nonatomic, readonly, getter = isWrapEnabled) BOOL wrapEnabled;
@property (nonatomic, assign) BOOL bounces;
@property (nonatomic, assign) CGFloat scrollOffset;
@property (nonatomic, readonly) CGFloat offsetMultiplier;
@property (nonatomic, assign) CGSize contentOffset;
@property (nonatomic, assign) CGSize viewpointOffset;
@property (nonatomic, readonly) NSInteger numberOfItems;
@property (nonatomic, readonly) NSInteger numberOfPlaceholders;
@property (nonatomic, assign) NSInteger currentItemIndex;
@property (nonatomic, strong, readonly) UIView *currentItemView;
@property (nonatomic, strong, readonly) NSArray *indexesForVisibleItems;
@property (nonatomic, readonly) NSInteger numberOfVisibleItems;
@property (nonatomic, strong, readonly) NSArray *visibleItemViews;
@property (nonatomic, readonly) CGFloat itemWidth;
@property (nonatomic, strong, readonly) UIView *contentView;
@property (nonatomic, readonly) CGFloat toggle;
@property (nonatomic, assign) CGFloat autoscroll;
@property (nonatomic, assign) BOOL stopAtItemBoundary;
@property (nonatomic, assign) BOOL scrollToItemBoundary;
@property (nonatomic, assign) BOOL ignorePerpendicularSwipes;
@property (nonatomic, assign) BOOL centerItemWhenSelected;
@property (nonatomic, readonly, getter = isDragging) BOOL dragging;
@property (nonatomic, readonly, getter = isDecelerating) BOOL decelerating;
@property (nonatomic, readonly, getter = isScrolling) BOOL scrolling;

- (void)scrollByOffset:(CGFloat)offset duration:(NSTimeInterval)duration;
- (void)scrollToOffset:(CGFloat)offset duration:(NSTimeInterval)duration;
- (void)scrollByNumberOfItems:(NSInteger)itemCount duration:(NSTimeInterval)duration;
- (void)scrollToItemAtIndex:(NSInteger)index duration:(NSTimeInterval)duration;
- (void)scrollToItemAtIndex:(NSInteger)index animated:(BOOL)animated;

- (UIView *)itemViewAtIndex:(NSInteger)index;
- (NSInteger)indexOfItemView:(UIView *)view;
- (NSInteger)indexOfItemViewOrSubview:(UIView *)view;
- (CGFloat)offsetForItemAtIndex:(NSInteger)index;
- (UIView *)itemViewAtPoint:(CGPoint)point;

- (void)removeItemAtIndex:(NSInteger)index animated:(BOOL)animated;
- (void)insertItemAtIndex:(NSInteger)index animated:(BOOL)animated;
- (void)reloadItemAtIndex:(NSInteger)index animated:(BOOL)animated;

- (void)reloadData;

@end


@protocol JZDataSource <NSObject>

- (NSInteger)numberOfItemsInJZStackedView:(JZ *)JZStackedView;
- (UIView *)JZStackedView:(JZ *)JZStackedView viewForItemAtIndex:(NSInteger)index reusingView:(UIView *)view;

@optional

- (NSInteger)numberOfPlaceholdersInJZStackedView:(JZ *)JZStackedView;
- (UIView *)JZStackedView:(JZ *)JZStackedView placeholderViewAtIndex:(NSInteger)index reusingView:(UIView *)view;

@end


@protocol JZDelegate <NSObject>
@optional

- (void)JZStackedViewWillBeginScrollingAnimation:(JZ *)JZStackedView;
- (void)JZStackedViewDidEndScrollingAnimation:(JZ *)JZStackedView;
- (void)JZStackedViewDidScroll:(JZ *)JZStackedView;
- (void)JZStackedViewCurrentItemIndexDidChange:(JZ *)JZStackedView;
- (void)JZStackedViewWillBeginDragging:(JZ *)JZStackedView;
- (void)JZStackedViewDidEndDragging:(JZ *)JZStackedView willDecelerate:(BOOL)decelerate;
- (void)JZStackedViewWillBeginDecelerating:(JZ *)JZStackedView;
- (void)JZStackedViewDidEndDecelerating:(JZ *)JZStackedView;

- (BOOL)JZStackedView:(JZ *)JZStackedView shouldSelectItemAtIndex:(NSInteger)index;
- (void)JZStackedView:(JZ *)JZStackedView didSelectItemAtIndex:(NSInteger)index;

- (CGFloat)JZStackedViewItemWidth:(JZ *)JZStackedView;
- (CATransform3D)JZStackedView:(JZ *)JZStackedView itemTransformForOffset:(CGFloat)offset baseTransform:(CATransform3D)transform;
- (CGFloat)JZStackedView:(JZ *)JZStackedView valueForOption:(JZOption)option withDefault:(CGFloat)value;

@end

#pragma GCC diagnostic pop

