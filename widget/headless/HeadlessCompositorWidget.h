/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef widget_headless_HeadlessCompositorWidget_h
#define widget_headless_HeadlessCompositorWidget_h

<<<<<<< ours
=======
#include "mozilla/ReentrantMonitor.h"
#include "HeadlessWidget.h"
>>>>>>> theirs
#include "mozilla/widget/CompositorWidget.h"
#include "mozilla/widget/HeadlessWidget.h"

namespace mozilla {
namespace widget {

class HeadlessCompositorWidgetInitData;

class HeadlessCompositorWidget : public CompositorWidget,
                                 public CompositorWidgetDelegate {
 public:
  HeadlessCompositorWidget(const HeadlessCompositorWidgetInitData& aInitData,
                           const layers::CompositorOptions& aOptions,
                           HeadlessWidget* aWindow);

<<<<<<< ours
  void NotifyClientSizeChanged(const LayoutDeviceIntSize& aClientSize) override;
=======
  void NotifyClientSizeChanged(const LayoutDeviceIntSize& aClientSize);
  void SetSnapshotListener(HeadlessWidget::SnapshotListener&& listener);
>>>>>>> theirs

  // CompositorWidget Overrides
  already_AddRefed<gfx::DrawTarget> StartRemoteDrawingInRegion(
      const LayoutDeviceIntRegion& aInvalidRegion) override;

  uintptr_t GetWidgetKey() override;

  LayoutDeviceIntSize GetClientSize() override;

  nsIWidget* RealWidget() override;
  CompositorWidgetDelegate* AsDelegate() override { return this; }

  void ObserveVsync(VsyncObserver* aObserver) override;

  // CompositorWidgetDelegate Overrides

  HeadlessCompositorWidget* AsHeadlessCompositorWidget() override {
    return this;
  }

 private:
  void UpdateDrawTarget(const LayoutDeviceIntSize& aClientSize);
  void PeriodicSnapshot();
  void TakeSnapshot();

  HeadlessWidget* mWidget;
  mozilla::ReentrantMonitor mMon;

  // See GtkCompositorWidget for the justification for this mutex.
  DataMutex<LayoutDeviceIntSize> mClientSize;

  HeadlessWidget::SnapshotListener mSnapshotListener;
  RefPtr<gfx::DrawTarget> mDrawTarget;
};

}  // namespace widget
}  // namespace mozilla

#endif  // widget_headless_HeadlessCompositor_h
