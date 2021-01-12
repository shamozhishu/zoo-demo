#ifndef __UI_ACTIVATOR_H__
#define __UI_ACTIVATOR_H__

#include <zoo/Log.h>
#include <zoo/Utils.h>
#include <QStyledItemDelegate>
#include <ctkPluginActivator.h>

class MainWindow;
class NoFocusDelegate : public QStyledItemDelegate
{
public:
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
	{
		QStyleOptionViewItem itemOption(option);
		if (itemOption.state & QStyle::State_HasFocus)
			itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
		QStyledItemDelegate::paint(painter, itemOption, index);
	}
};

class UIActivator : public QObject, public ctkPluginActivator
{
	Q_OBJECT
	Q_INTERFACES(ctkPluginActivator)
	Q_PLUGIN_METADATA(IID "ctk_flight_control_ui")
public:
	UIActivator();
	void start(ctkPluginContext* context);
	void stop(ctkPluginContext* context);
	template<typename T>
	static T* getService()
	{
		ctkServiceReference ref = _pluginContext->getServiceReference<T>();
		if (ref)
			return qobject_cast<T*>(_pluginContext->getService(ref));

		zoo_warning(zoo::utf8ToAnsi("»ñÈ¡¡°ctkServiceReference of UIManagerService¡±Îª¿Õ£¡").c_str());
		return nullptr;
	}

	static void sendWarCmd(QString cmdline);
	static ctkPluginContext* getPluginContext();

private:
	MainWindow* _mainUI;
	static ctkPluginContext* _pluginContext;
};

#endif // __UI_ACTIVATOR_H__
