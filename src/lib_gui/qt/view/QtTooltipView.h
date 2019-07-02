#ifndef QT_TOOLTIP_VIEW
#define QT_TOOLTIP_VIEW

#include "TooltipView.h"
#include "QtThreadedFunctor.h"

class QTimer;
class QtTooltip;

class QtTooltipView
	: public TooltipView
{
public:
	QtTooltipView(ViewLayout* viewLayout);
	~QtTooltipView() = default;

	// View implementation
	void createWidgetWrapper() override;
	void refreshView() override;

	// TooltipView implementation
	void showTooltip(TooltipInfo info, const View* parent) override;
	void hideTooltip(bool force) override;

	bool tooltipVisible() const override;

private:
	QtThreadedLambdaFunctor m_onQtThread;

	QtTooltip* m_widget;
};

#endif // QT_TOOLTIP_VIEW
