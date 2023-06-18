/******************************************************************************************************************************************/
// File : Application.hpp
// Purpose : Application creating, setting the builders and produce them via Ioc
/******************************************************************************************************************************************/
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Builders/ServiceBuilder.hpp"
#include "Builders/EngineBuilder.hpp"
#include "IocModule.hpp"
#include "IService.hpp"
#include <cassert>

namespace Starting {

	class Application
	{
	public:
		Application();
		template<typename T>
		void SetServiceBuilder()
		{
			std::unique_ptr<IoC::IocModule> ioc_module = std::make_unique<IoC::IocModule>();
			ioc_module->LoadService<T>(m_service_builder);
			ioc_module.reset();
		}
		template<typename T>
		void SetEngineBuilder()
		{
			std::unique_ptr<IoC::IocModule> ioc_module = std::make_unique<IoC::IocModule>();
			ioc_module->LoadEngine<T>(m_engine_builder);
			ioc_module.reset();
		}
		void EndingBuilders();
		void StartAllBuilders();

	private:
		Builders::ServiceBuilder* m_service_builder = nullptr;
		Builders::EngineBuilder* m_engine_builder = nullptr;
	};

}

#endif